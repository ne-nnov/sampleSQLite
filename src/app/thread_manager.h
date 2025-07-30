//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

// Qt includes

// STL includes
#include <atomic>
#include <string>

class model_counters;

//! A class for executing tasks in a separate thread.
//! Internally, it uses a thread implemented via the STL 
class thread_manager
{
public:
  //! Constructor.
  //! @param[in] model A model to be modified by thread calls.
  thread_manager(model_counters* model);

  //! Destructor.
  ~thread_manager() {}

  //! It creates an instance of a thread and starts it.
  void launchThread();

  //! Stops the counters increase.
  void stopCounters();

  //! Continues the counters increase.
  void startCounters();

protected:
  //! Task to increase counters of the model.
  virtual void incrementCounters();

private:
  model_counters* m_model; //!< model to be modified by thread calls.
  std::atomic<bool> m_countersActive; //!< state whether the counters are increased at the moment.
};
