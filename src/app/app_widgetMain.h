//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

// Qt includes
#include <QWidget>
#include <QTimer>
#include <QTime>

class model_counters;
class thread_manager;

class QCheckBox;
class QCloseEvent;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QTableView;

//! This class creates the application's main window and contains a table along with
//! buttons for interacting with it. The buttons provide functionality to:
//! add a row, delete a row, and save data to the database.
//! There is 'More' check button to show additional controls:
//! - stop/start counters;
//! - display the data base table content;
//! - button to add 1000 rows immediatelly;
//! - sum of counters in t0;
//! - t1-t0 value in seconds.
class app_widgetMain : public QWidget
{
  Q_OBJECT

public:
  //! Constructor.
  //! @param[in] parent parent widget.
  app_widgetMain(QWidget* parent = 0);
  //! Destructor.
  ~app_widgetMain();

  //! Set the source data model.
  //! @param[in] model Data retrieval model.
  void setModel(model_counters* model);

  //! Set the thread manager.
  //! @param[in] manager thread management controller.
  void setThreadManager(thread_manager* manager);

  //! Starts the thread manager.
  void startCounters();

  //! Updates the table view and frequency control values.
  void updateControls();

  //! Returns the complete path to the database file.
  static QString dataBaseFileName();

protected:
  //! This event handler is called with the given event when Qt receives a window close request for a top
  //! - level widget from the window system.
  //! Blocks execution until the thread manager completes the current task. Then the execution goes to the parent.
  virtual void closeEvent(QCloseEvent* event);

private slots:
  //!< Shows additional UI controls.
  void onMore();
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

  //! Updates table values and frequency label according to the model content.
  void onTimer();

private:
  model_counters* m_model;        //!< model containing the current counter data.
  thread_manager* m_threadManager; //!< thread management controller.

  QTimer          m_timer;        //!< timer to update UI controls by the model.
  QTime           m_timeStart;    //!< t0, the time of thread counter start.
  double          m_countersSumStart; //!< frequency at t0.

  QLabel*         m_frequencyLbl; //!< control showing the current frequency value.

  QTableView*     m_modelTable;   //!< control showing the current counter data.
  QTableView*     m_SQLiteTable;  //!< control showing SQLite data base data.

  QCheckBox*      m_additionalChk; //!< control to use additional UI controls.
  QGroupBox*      m_additionalGroupBox; //!< group box of additional UI controls.

  QPushButton*    m_startBtn;     //!< control starting counter increase.
  QPushButton*    m_stopBtn;      //!< control to stop counter increase.
  QPushButton*    m_dbTableBtn;   //!< control to show control showing SQLite table.
  QPushButton*    m_addManyBtn;   //!< control to add many rows in the table.
  QLineEdit*      m_countersSumStartEdt; //!< control showing sum of counters at t0.
  QLabel*         m_secondsInfoLbl; //!< control showing seconds since system start.

  QPushButton*    m_addBtn;       //!< control to add a new row in the table.
  QPushButton*    m_removeBtn;    //!< control to remove the selected row from the table.
  QPushButton*    m_saveBtn;      //!< control to save table of counters into data base.
};
