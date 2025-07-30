//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Qt includes
#include <QWidget>

class model_counters;

//! This class creates the application's main window and contains a table along with
//! buttons for interacting with it. The buttons provide functionality to:
//! add a row, delete a row, and save data to the database.
class app_widgetMain : public QWidget
{
  Q_OBJECT

public:
  //! Constructor.
  app_widgetMain(QWidget* parent = 0);
  //! Destructor.
  ~app_widgetMain() {}

  //! Set the source data model.
  //! @param[in] model Data retrieval model.
  void setModel(model_counters* model);

private:
  model_counters* m_model; //<! data retrieval model.
};
