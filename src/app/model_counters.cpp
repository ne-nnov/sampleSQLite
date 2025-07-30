//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include <model_counters.h>

// Qt includes

// STL includes
#include <iostream>

//-----------------------------------------------------------------------------
model_counters::model_counters()
{
}

//-----------------------------------------------------------------------------
void model_counters::printMessage()
{
  int counter = 0;
  while (true)
  {
    std::cout << "printMessage counter: " << counter++ << std::endl;
  }
}
