//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

// Qt includes
#include <QWidget>

class model_counters;
class thread_manager;

class QLabel;
class QPushButton;
class QTableView;

//! This class creates the application's main window and contains a table along with
//! buttons for interacting with it. The buttons provide functionality to:
//! add a row, delete a row, and save data to the database.
//! Additionaly the advanced mode is impelemented. It contains actions to:
//! - stop/start counters;
//! - display the data base table content.
class app_widgetMain : public QWidget
{
  Q_OBJECT

public:
  //! Constructor.
  //! @param[in] parent parent widget.
  //! @param[in] advancedMode flag whether auxiliary controls are shown.
  app_widgetMain(QWidget* parent, bool advancedMode);
  //! Destructor.
  ~app_widgetMain() {}

  //! Set the source data model.
  //! @param[in] model Data retrieval model.
  void setModel(model_counters* model);

  //! Set the thread manager.
  //! @param[in] manager thread management controller.
  void setThreadManager(thread_manager* manager);

  //! Updates text of label, that shows frequency value.
  void updateFrequency();

private slots:
  //! Starts counters increase. (Available only in 'advanced' mode)
  void onStart();
  //! Stops counters increase. (Available only in 'advanced' mode)
  void onStop();
  //! Shows table that shows SQLite data base content.
  //! (Available only in 'advanced' mode)
  void onSQLite();
  //! Appends many rows in the table.
  void onAddMany();

  //! Appends a new row in the table.
  void onAdd();
  //! Removes selected row of the table.
  void onRemove();
  //! Saves the table content to SQLite data base.
  void onSave();

private:
  model_counters* m_model;        //!< model containing the current counter data.
  thread_manager* m_threadManager; //!< thread management controller.

  QLabel*         m_frequencyLbl; //!< control showing the current frequency value.

  QTableView*     m_modelTable;   //!< control showing the current counter data.
  QTableView*     m_SQLiteTable;  //!< control showing SQLite data base data.

  QPushButton*    m_startBtn;     //!< control starting counter increase.
  QPushButton*    m_stopBtn;      //!< control to stop counter increase.
  QPushButton*    m_addManyBtn;   //!< control to add many rows in the table.
  QPushButton*    m_dbTableBtn;   //!< control to show control showing SQLite table.

  QPushButton*    m_addBtn;       //!< control to add a new row in the table.
  QPushButton*    m_removeBtn;    //!< control to remove the selected row from the table.
  QPushButton*    m_saveBtn;      //!< control to save table of counters into data base.
};
