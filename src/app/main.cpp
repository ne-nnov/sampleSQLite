//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include <app_widgetMain.h>

// model includes
#include <model_counters.h>
#include <model_dataBase.h>

// thread includes
#include <thread_manager.h>

// Qt includes
#include <QApplication>

// STL includes
#include <iostream>
#include <iostream>
#include <thread>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  model_dataBase::connectToDatabase(app_widgetMain::dataBaseFileName());

  // Create data model
  model_counters* model = new model_counters();

  model->setCounters(model_dataBase::getCounters());

  // Constructs the new thread and runs it. Does not block execution.
  thread_manager* thmanager = new thread_manager();
  thmanager->setModel(model);
  thmanager->launchThread();

  app_widgetMain* mainWidget = new app_widgetMain(0, true);
  mainWidget->setModel(model);
  mainWidget->setThreadManager(thmanager);

  //mainWidget->startCounters();

  mainWidget->resize(300, 600);
  mainWidget->show();

  int state = app.exec();

  thmanager->setModel(nullptr);
  thmanager->stopCounters();

  delete model;
  delete thmanager;

  return state;
}
