//-----------------------------------------------------------------------------
// Created on: 29 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Qt includes
#include <QApplication>
#include <QWidget>

// STL includes
#include <iostream>

int main(int argc, char* argv[])
{
  QApplication app(argc, argv);

  QWidget* widget = new QWidget();
  widget->resize(300, 200);
  widget->show();

  return app.exec();
}
