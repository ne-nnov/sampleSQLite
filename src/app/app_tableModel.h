//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

// Qt includes
#include <QAbstractTableModel>

// model includes
#include <model_counters.h>

//! A class for displaying data model contents in a table format.
class app_tableModel : public QAbstractTableModel
{
public:
  //! Constructor.
  //! @param[in] parent the parent widget.
  app_tableModel(QObject* parent = 0);
  //! Destructor.
  ~app_tableModel() {}

  //! Set the source data model.
  //! @param[in] model Data retrieval model.
  void setModel(model_counters* model) { m_model = model; }

  //! Emits model update signals for dependent UI controls.
  void emitModelChanged();

  //! Reimplemented QAbstractTableModel virtual methods

  //! Returns the data stored under the given role for the item referred to by the index.
  //! @param[in] parent index that indicates the location of an item in the model.
  //! @return number of rows.
  virtual int rowCount(const QModelIndex& parent = QModelIndex()) const;

  //! Returns the number of columns for the children of the given parent.
  //! @param[in] parent index that indicates the location of an item in the model.
  //! @return number of columns.
  virtual int columnCount(const QModelIndex& parent = QModelIndex()) const;

  //! Returns the data stored under the given role for the item referred to by the index.
  //! @param[in] index index that indicates the location of an item in the model.
  //! @param[in] role type of returned value. It can be text, decoration role, style of the item.
  //! @return value for the item.
  virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

  //! Returns the data for the given role and section in the header with the specified orientation.
  //! @param[in] section index that indicates the item position in the header.
  //! @param[in] orientation the header orientation.
  //! @return header value for the item.
  virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

  //! Returns the item flags for the given index.
  //! @param[in] index index that indicates the location of an item in the model.
  virtual Qt::ItemFlags flags(const QModelIndex& theIndex) const;

private:
  model_counters* m_model;        //!< model containing the current counter data.
};
