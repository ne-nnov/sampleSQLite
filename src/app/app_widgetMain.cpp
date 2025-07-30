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

// Qt includes
#include <QGridLayout>
#include <QHeaderView>
#include <QLabel>
#include <QPushButton>
#include <QSqlTableModel>
#include <QTableView>

//-----------------------------------------------------------------------------
app_widgetMain::app_widgetMain(QWidget* parent, bool advancedMode)
  : QWidget(parent),
  m_model(nullptr)
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
  m_modelTable->setSelectionMode(QAbstractItemView::SingleSelection);
  m_modelTable->setSelectionBehavior(QAbstractItemView::SelectRows);
  app_tableModel* dataModel = new app_tableModel(this);
  m_modelTable->setModel(dataModel);
  layout->addWidget(m_modelTable, 1, 0, 1, 3);

  // stop/start buttons
  if (advancedMode)
  {
    m_startBtn = new QPushButton("start", this);
    m_stopBtn = new QPushButton("stop", this);
    m_dbTableBtn = new QPushButton("SQLite", this);
    m_dbTableBtn->setCheckable(true);
    m_dbTableBtn->setChecked(false);

    connect(m_startBtn, SIGNAL(clicked()), this, SLOT(onStart()));
    connect(m_stopBtn, SIGNAL(clicked()), this, SLOT(onStop()));
    connect(m_dbTableBtn, SIGNAL(clicked()), this, SLOT(onSQLite()));

    layout->addWidget(m_startBtn, 2, 0);
    layout->addWidget(m_stopBtn, 2, 1);
    layout->addWidget(m_dbTableBtn, 2, 2);

    // data base's content table
    QSqlTableModel* model = new QSqlTableModel(this);
    model->setTable(model_dataBase::tableName());
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Key"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Counter"));

    m_SQLiteTable = new QTableView(this);
    m_SQLiteTable->setModel(model);
    layout->addWidget(m_SQLiteTable, 3, 0, 1, 3);
    onSQLite();
  }

  // add/remove/save buttons
  m_addBtn = new QPushButton("add", this);
  m_removeBtn = new QPushButton("remove", this);
  m_saveBtn = new QPushButton("save", this);

  connect(m_addBtn, SIGNAL(clicked()), this, SLOT(onAdd()));
  connect(m_removeBtn, SIGNAL(clicked()), this, SLOT(onRemove()));
  connect(m_saveBtn, SIGNAL(clicked()), this, SLOT(onSave()));

  layout->addWidget(m_addBtn, 4, 0);
  layout->addWidget(m_removeBtn, 4, 1);
  layout->addWidget(m_saveBtn, 4, 2);
}

//-----------------------------------------------------------------------------
void app_widgetMain::setModel(model_counters* model)
{
  m_model = model;
  dynamic_cast<app_tableModel*>(m_modelTable->model())->setModel(model);
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
  m_model->startCounters();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onStop()
{
  if (!m_model)
    return;
  m_model->stopCounters();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onSQLite()
{
  m_SQLiteTable->setVisible(m_dbTableBtn->isChecked());
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
  int rowSelectedId = selectedRows.empty() ? -1 : selectedRows.first().row();

  m_model->removeCounter(rowSelectedId);
  dynamic_cast<app_tableModel*>(m_modelTable->model())->emitModelChanged();
}

//-----------------------------------------------------------------------------
void app_widgetMain::onSave()
{
}
