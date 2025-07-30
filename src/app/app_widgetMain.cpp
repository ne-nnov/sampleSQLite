//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include "app_widgetMain.h"

// model includes
#include "model_dataBase.h"

// Qt includes
#include <QGridLayout>
#include <QSqlTableModel>
#include <QTableView>

//-----------------------------------------------------------------------------
app_widgetMain::app_widgetMain(QWidget* parent)
  : QWidget(parent)
{
  setWindowTitle("C++ (Qt) Qualification Test");
  QGridLayout* layout = new QGridLayout(this);

  // table with the current state of the DataBase
  QSqlTableModel* model = new QSqlTableModel();
  model->setTable(model_dataBase::tableName());
  model->setEditStrategy(QSqlTableModel::OnManualSubmit);
  model->select();
  model->setHeaderData(0, Qt::Horizontal, QObject::tr("Key"));
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("Counter"));

  QTableView* view = new QTableView(this);
  view->setModel(model);

  layout->addWidget(view);
}
