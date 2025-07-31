//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

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
  thread_manager();

  //! Destructor.
  ~thread_manager();

  //! Set the source data model.
  //! @param[in] model Data retrieval model.
  void setModel(model_counters* model) { m_model = model; }

  //! It creates an instance of a thread and starts it.
  void launchThread();

  //! Returns true if the counters are started.
  bool isStarted() const;

  //! Returns true if previous incrementCounters for model finished and new one hasn't begun.
  bool isCountersDone() const;

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
  std::atomic<bool> m_countersDone;   //!< state whether the previous increment finished and new one hasn't begun.
};
