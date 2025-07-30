//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

//! Qt includes
#include <QString>

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
  //! @param[in] toInit flag whether to init the data base with default values.
  //! @return boolean value of open success.

  static bool connectToDatabase(const QString& fileName,
                                const bool     toInit);

  //! Returns the name of the data base main table.
  static QString tableName() { return "Counter"; }

  //! Returns the name of the data base.
  static QString dataBaseName() { return "testSqlBase.sqlite3"; }
};
