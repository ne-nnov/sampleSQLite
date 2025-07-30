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
: m_countersActive (false)
{
}

//-----------------------------------------------------------------------------
void model_counters::printMessage()
{
  int counter = 0;
  while (true)
  {
    if (!m_countersActive)
      continue;

    std::cout << "printMessage counter: " << counter++ << std::endl;
  }
}

//-----------------------------------------------------------------------------
void model_counters::stopCounters()
{
  m_countersActive = false;
}

//-----------------------------------------------------------------------------
void model_counters::startCounters()
{
  m_countersActive = true;
}

//-----------------------------------------------------------------------------
int model_counters::getFrequency() const
{
  return 6;
}
