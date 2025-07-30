//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

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

  //! 
  static bool connectToDatabase(const bool toInit);

  //!
  static QString tableName() { return "Counter"; }

  //!
  static QString dataBaseName() { return "testSqlBase.sqlite3"; }
};
