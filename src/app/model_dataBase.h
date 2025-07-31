//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

//! Qt includes
#include <QString>

//! model includes
#include <model_counters.h>

//! The class implements interaction with an SQLite database and provides an interface
//! for accessing the required data.
class model_dataBase
{
public:
  //! Constructor.
  model_dataBase();
  //! Destructor.
  ~model_dataBase() {}

  //! It connects the application to SQLite data base.
  //! @param[in] fileName A name of the data base.
  //! @return boolean value of open success.
  static bool connectToDatabase(const QString& fileName);

  //! Returns the SQL data base table values.
  //! @return container of values.
  static CountersMap getCounters();

  //! Fills the SQL data base table with values.
  //! @param values container of values.
  static void setCounters(const CountersMap& values);

  //! Returns the name of the data base main table.
  static QString tableName() { return "Counter"; }

  //! Returns the name of the data base.
  static QString dataBaseName() { return "testSqlBase.sqlite3"; }
};
