//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include <model_counters.h>

// Qt includes

// STL includes
#include <algorithm>
#include <iostream>

#define DEBUG_CODE

//-----------------------------------------------------------------------------
model_counters::model_counters()
{
}

//-----------------------------------------------------------------------------
void model_counters::addCounter()
{
  m_counters.push_back(model_counters::defaultValue());
}

//-----------------------------------------------------------------------------
bool model_counters::removeCounter(const int position)
{
  if (m_counters.empty())
    return false;

  if (position == -1)
    m_counters.erase(m_counters.begin() + m_counters.size() - 1);
  else
    m_counters.erase(m_counters.begin() + position);

  return true;
}

//-----------------------------------------------------------------------------
void model_counters::incrementCounters()
{
  std::transform(std::begin(m_counters), std::end(m_counters), std::begin(m_counters), [](int x) {return x + 1; });

#ifdef DEBUG_CODE
  std::cout << "incrementCounters:" << std::endl;
  for (auto& element : m_counters)
  {
    std::cout << element << std::endl;
  }
#endif
}

//-----------------------------------------------------------------------------
int model_counters::getFrequency() const
{
  return 6;
}
