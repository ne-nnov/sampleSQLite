//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include "app_widgetMain.h"

// model includes
#include "model_dataBase.h"

// Qt includes
#include <QApplication>

// STL includes
#include <iostream>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  if (!model_dataBase::connectToDatabase(true))
    return -1;

  app_widgetMain* widget = new app_widgetMain();
  widget->resize(300, 200);
  widget->show();

  return app.exec();
}
