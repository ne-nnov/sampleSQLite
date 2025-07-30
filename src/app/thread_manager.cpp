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
thread_manager::thread_manager(model_counters* model)
: m_model(model)
{
}

//-----------------------------------------------------------------------------
void thread_manager::launchThread()
{
  std::thread t1(&thread_manager::incrementCounters, this);
  t1.detach();
}

//-----------------------------------------------------------------------------
void thread_manager::incrementCounters()
{
  m_model->printMessage();
}
