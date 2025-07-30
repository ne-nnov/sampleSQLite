//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include "app_widgetMain.h"
#include "app_tableModel.h"

// model includes
#include "model_counters.h"
#include "model_dataBase.h"

// thread includes
#include "thread_manager.h"

// Qt includes
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSqlTableModel>
#include <QTableView>

const int ADD_MANY_VALUES = 1000;

//-----------------------------------------------------------------------------
app_widgetMain::app_widgetMain(QWidget* parent, bool advancedMode)
  : QWidget(parent),
  m_model(nullptr),
  m_threadManager(nullptr)
{
  setWindowTitle("C++ (Qt) Qualification Test");
  QGridLayout* layout = new QGridLayout(this);

  // frequency label
  QWidget* frequencyWdg = new QWidget(this);
  QHBoxLayout* frequencyWdgLay = new QHBoxLayout(frequencyWdg);
  layout->addWidget(frequencyWdg, 0, 0, 1, 3);

  m_frequencyLbl = new QLabel(frequencyWdg);
  QPalette pal = m_frequencyLbl->palette();
  pal.setColor(QPalette::Window, Qt::lightGray);
  m_frequencyLbl->setAutoFillBackground(true);
  m_frequencyLbl->setPalette(pal);
  updateFrequency();

  frequencyWdgLay->addWidget(new QLabel("Counter Increment Frequency:", frequencyWdg));
  frequencyWdgLay->addWidget(m_frequencyLbl);

  // model table
  m_modelTable = new QTableView(this);
  m_modelTable->setSelectionMode(QAbstractItemView::MultiSelection);
  m_modelTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  app_tableModel* dataModel = new app_tableModel(this);
  m_modelTable->setModel(dataModel);
  layout->addWidget(m_modelTable, 1, 0, 1, 3);

  // stop/start buttons
  if (advancedMode)
  {
    m_startBtn = new QPushButton("start", this);
    m_stopBtn = new QPushButton("stop", this);
    m_addManyBtn = new QPushButton("add 1000", this);
    m_dbTableBtn = new QPushButton("SQLite", this);
    m_dbTableBtn->setCheckable(true);
    m_dbTableBtn->setChecked(false);

    connect(m_startBtn, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(m_stopBtn, SIGNAL(clicked()), this, SLOT(onStop()));
    connect(m_dbTableBtn, SIGNAL(clicked()), this, SLOT(onSQLite()));
    connect(m_addManyBtn, SIGNAL(clicked()), this, SLOT(onAddMany()));

    layout->addWidget(m_startBtn, 2, 0);
    layout->addWidget(m_stopBtn, 2, 1);
    layout->addWidget(m_dbTableBtn, 2, 2);
    layout->addWidget(m_addManyBtn, 3, 0);

    // data base's content table
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable(model_dataBase::tableName());
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Key"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Counter"));

    m_SQLiteTable = new QTableView(this);
    m_SQLiteTable->setModel(model);
    layout->addWidget(m_SQLiteTable, 4, 0, 1, 3);
    onSQLite();
  }

  // add/remove/save buttons
  m_addBtn = new QPushButton("add", this);
  m_removeBtn = new QPushButton("remove", this);
  m_saveBtn = new QPushButton("save", this);

  connect(m_addBtn, SIGNAL(clicked()), this, SLOT(onAdd()));
  connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(onRemove()));
  connect(m_saveBtn, SIGNAL(clicked()), this, SLOT(onSave()));

  layout->addWidget(m_addBtn,    5, 0);
  layout->addWidget(m_removeBtn, 5, 1);
  layout->addWidget(m_saveBtn,   5, 2);

  connect(&m_timer, SIGNAL(timeout()), SLOT(onTimer()));
  m_timer.start(100);
}

//-----------------------------------------------------------------------------
app_widgetMain::~app_widgetMain()
{
  m_timer.stop();
}

//-----------------------------------------------------------------------------
void app_widgetMain::setModel(model_counters* model)
{
  m_model = model;
  dynamic_cast<app_tableModel*>(m_modelTable->model())->setModel(model);
}

//-----------------------------------------------------------------------------
void app_widgetMain::setThreadManager(thread_manager* manager)
{
  m_threadManager = manager;
}

//-----------------------------------------------------------------------------
void app_widgetMain::updateFrequency()
{
  m_frequencyLbl->setText(QString::number(m_model->getFrequency()));
}

//-----------------------------------------------------------------------------
void app_widgetMain::onStart()
{
  if (!m_model)
    return;
  m_threadManager->startCounters();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onStop()
{
  if (!m_model)
    return;
  m_threadManager->stopCounters();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onSQLite()
{
  m_SQLiteTable->setVisible(m_dbTableBtn->isChecked());
}

//-----------------------------------------------------------------------------
void app_widgetMain::onAddMany()
{
  if (!m_model)
    return;

  for (int i = 0; i < ADD_MANY_VALUES; i++)
    m_model->addCounter();

  dynamic_cast<app_tableModel*>(m_modelTable->model())->emitModelChanged();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onAdd()
{
  if (!m_model)
    return;

  m_model->addCounter();
  dynamic_cast<app_tableModel*>(m_modelTable->model())->emitModelChanged();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onRemove()
{
  if (!m_model)
    return;

  QModelIndexList selectedRows = m_modelTable->selectionModel()->selectedRows();
  if (selectedRows.empty())
    m_model->removeCounter(-1);
  else if (selectedRows.size() == 1)
  {
    m_model->removeCounter(selectedRows.first().row());
  }
  else
  {
    std::list<int> rowIds;
    for (int i = 0; i < selectedRows.size(); i++)
    {
      rowIds.push_back(selectedRows.at(i).row());
    }
    rowIds.unique();
    rowIds.sort();
    rowIds.reverse();

    for (int rowId : rowIds)
    {
      m_model->removeCounter(rowId);
    }
  }

  dynamic_cast<app_tableModel*>(m_modelTable->model())->emitModelChanged();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onSave()
{
}

//-----------------------------------------------------------------------------
void app_widgetMain::onTimer()
{
  m_frequencyLbl->setText(QString::number(m_model->getFrequency()));
  dynamic_cast<app_tableModel*>(m_modelTable->model())->emitModelChanged();
}