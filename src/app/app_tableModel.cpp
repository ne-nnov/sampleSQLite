//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include <app_tableModel.h>

// model includes
#include "model_counters.h"

// Qt includes

//-----------------------------------------------------------------------------
app_tableModel::app_tableModel(QObject* parent)
: QAbstractTableModel(parent),
  m_model(nullptr)
{
}

//-----------------------------------------------------------------------------
int app_tableModel::rowCount(const QModelIndex& parent) const
{
  return 3;
}

//-----------------------------------------------------------------------------
int app_tableModel::columnCount(const QModelIndex& parent) const
{
  return 2;
}

//-----------------------------------------------------------------------------
QVariant app_tableModel::data(const QModelIndex& index, int role) const
{
  if (role == Qt::DisplayRole)
    return "data value";

  return QVariant();
}

//-----------------------------------------------------------------------------
QVariant app_tableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return section == 0 ? "Id" : "Counter";

  return QAbstractTableModel::headerData(section, orientation, role);
}
