//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include "model_dataBase.h"

// Qt includes
#include <QDir>
#include <QFile>
#include <QStandardPaths>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

// STL includes
#include <iostream>

//-----------------------------------------------------------------------------
model_dataBase::model_dataBase()
{
}

//-----------------------------------------------------------------------------
bool model_dataBase::connectToDatabase(const bool toInit)
{
  QSqlDatabase database = QSqlDatabase::database();
  if (!database.isValid()) {
    database = QSqlDatabase::addDatabase("QSQLITE");
    if (!database.isValid())
    {
      std::cout << "Cannot add database: "
                << qPrintable(database.lastError().text()) << std::endl;
      return false;
    }
  }

  const QDir writeDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
  if (!writeDir.mkpath("."))
  {
    std::cout << "Failed to create writable directory at"
              << qPrintable(writeDir.absolutePath()) << std::endl;
    return false;
  }

  // Ensure that we have a writable location on all devices.
  const QString fileName = writeDir.absolutePath() + "/" + dataBaseName();

  // When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
  database.setDatabaseName(fileName);
  if (!database.open()) {
    std::cout << "Cannot open database: "
              << qPrintable(database.lastError().text()) << std::endl;
    QFile::remove(fileName);
    return false;
  }

  if (toInit)
  {
    QString name = tableName();

    QSqlQuery q("", database);
    q.exec(QString("drop table %1").arg(name));
    q.exec(QString("create table %1 (id int primary key, "
                                    "valuecounter int)").arg(name));

    q.exec(QString("insert into %1 values(0, 0)").arg(name));
    q.exec(QString("insert into %1 values(1, 10)").arg(name));
    q.exec(QString("insert into %1 values(2, 20)").arg(name));
  }
  return true;
}
