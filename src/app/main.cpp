//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include "app_widgetMain.h"

// model includes
#include "model_counters.h"
#include "model_dataBase.h"

// thread includes
#include "thread_manager.h"

// Qt includes
#include <QApplication>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  if (!model_dataBase::connectToDatabase(true))
    return -1;

  // Create data model
  model_counters* model = new model_counters();

  // Constructs the new thread and runs it. Does not block execution.
  thread_manager manager(model);
  manager.launchThread();

  app_widgetMain* widget = new app_widgetMain();
  widget->setModel(model);

  widget->resize(600, 500);
  widget->show();

  int state = app.exec();

  delete model;

  return state;
}
