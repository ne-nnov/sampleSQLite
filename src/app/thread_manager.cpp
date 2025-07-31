//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include <thread_manager.h>

// model includes
#include <model_counters.h>

// Qt includes

// STL includes
#include <iostream>
#include <thread>

//-----------------------------------------------------------------------------
thread_manager::thread_manager()
: m_model(nullptr),
  m_countersActive(false)
{
}

//-----------------------------------------------------------------------------
thread_manager::~thread_manager()
{
}

//-----------------------------------------------------------------------------
bool thread_manager::isStarted() const
{
  return m_countersActive;
}

//-----------------------------------------------------------------------------
void thread_manager::launchThread()
{
  std::thread t1(&thread_manager::incrementCounters, this);
  t1.detach();
}

//-----------------------------------------------------------------------------
void thread_manager::stopCounters()
{
  m_countersActive = false;
}

//-----------------------------------------------------------------------------
void thread_manager::startCounters()
{
  m_countersActive = true;
}

//-----------------------------------------------------------------------------
void thread_manager::incrementCounters()
{
  while (true)
  {
    if (!m_model)
      continue;

    if (!m_countersActive)
      continue;
    m_model->incrementCounters();
  }
}
