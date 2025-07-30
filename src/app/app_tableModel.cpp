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
void app_tableModel::emitModelChanged()
{
  emit layoutChanged();
}

//-----------------------------------------------------------------------------
int app_tableModel::rowCount(const QModelIndex& parent) const
{
  return m_model ? m_model->getCounters().size() : 0;
}

//-----------------------------------------------------------------------------
int app_tableModel::columnCount(const QModelIndex& parent) const
{
  return 1;
}

//-----------------------------------------------------------------------------
QVariant app_tableModel::data(const QModelIndex& index, int role) const
{
  if (!m_model || role != Qt::DisplayRole)
    return QVariant();

  if (index.row() > m_model->getCounters().size())
    return QVariant();

  return m_model->getCounters().at(index.row());
}

//-----------------------------------------------------------------------------
QVariant app_tableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return "Counter";

  return QAbstractTableModel::headerData(section, orientation, role);
}
