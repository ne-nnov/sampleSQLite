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
bool model_dataBase::connectToDatabase(const QString& fileName)
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

  // When using the SQLite driver, open() will create the SQLite database if it doesn't exist.
  database.setDatabaseName(fileName);
  if (!database.open()) {
    std::cout << "Cannot open database: "
              << qPrintable(database.lastError().text()) << std::endl;
    QFile::remove(fileName);
    return false;
  }
  return true;
}

//-----------------------------------------------------------------------------
CountersMap model_dataBase::getCounters()
{
  CountersMap values;

  QSqlQuery query;
  query.exec(QString("SELECT valuecounter FROM %1").arg(tableName()));

  while (query.next())
  {
    int counter = query.value(0).toInt();
    values.push_back(counter);
  }

  return values;
}

//-----------------------------------------------------------------------------
void model_dataBase::setCounters(const CountersMap& values)
{
  QSqlDatabase database = QSqlDatabase::database();
  QString name = tableName();

  QSqlQuery q("", database);
  q.exec(QString("drop table %1").arg(name));
  q.exec(QString("create table %1 (id int primary key, "
    "valuecounter int)").arg(name));

  int id = 0;
  for (auto& element : values)
  {
    q.exec(QString("insert into %1 values(%2, %3)").arg(name).arg(id++).arg(element));
  }
}
