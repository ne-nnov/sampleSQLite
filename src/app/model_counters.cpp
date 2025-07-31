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
#include <mutex>

//#define DEBUG_CODE

std::mutex mtx;

//-----------------------------------------------------------------------------
model_counters::model_counters()
{
}

//-----------------------------------------------------------------------------
model_counters::~model_counters()
{
}

//-----------------------------------------------------------------------------
void model_counters::addCounter()
{
  m_mutex.lock();
  m_counters.push_back(model_counters::defaultValue());
  m_mutex.unlock();
}

//-----------------------------------------------------------------------------
bool model_counters::removeCounter(const int position)
{
  if (m_counters.empty())
    return false;

  m_mutex.lock();
  if (position == -1)
    m_counters.erase(m_counters.begin() + m_counters.size() - 1);
  else
    m_counters.erase(m_counters.begin() + position);
  m_mutex.unlock();

  return true;
}

//-----------------------------------------------------------------------------
void model_counters::setCounters(const CountersMap& values)
{
  m_mutex.lock();
  m_counters = values;
  m_mutex.unlock();
}

//-----------------------------------------------------------------------------
void model_counters::incrementCounters()
{
  m_mutex.lock();
  std::transform(std::begin(m_counters), std::end(m_counters), std::begin(m_counters), [](int x) {return x + 1; });
  m_mutex.unlock();

#ifdef DEBUG_CODE
  std::cout << "incrementCounters:" << std::endl;
  for (auto& element : m_counters)
  {
    std::cout << element << std::endl;
  }
#endif
}
