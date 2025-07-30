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
void model_counters::addCounter()
{
  int position = 0;
  if (!m_counters.empty())
    position = m_counters.rbegin()->first + 1;

  m_counters[position] = model_counters::defaultValue();
}

//-----------------------------------------------------------------------------
bool model_counters::removeCounter(const int position)
{
  if (m_counters.empty())
    return false;

  int lastPos = m_counters.rbegin()->first;
  if (position == -1 || position == m_counters.rbegin()->first)
  {
    m_counters.erase(m_counters.rbegin()->first);
  }
  else
  {
    CountersMap newMap;
    bool isItemRemoved = false;
    for (const auto& [key, value] : m_counters)
    {
      if (key == position)
        isItemRemoved = true;
      else
        newMap[isItemRemoved ? key - 1 : key] = value;
    }
    m_counters = newMap;
  }

  return true;
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
