//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

//! This class manages a set of counters, providing methods to:
//! - Add new counters;
//! - Remove existing counters;
//! - Retrieve available counters;
//! - Increment counter values.
class model_counters
{
public:
  //! Constructor.
  model_counters();
  //! Destructor.
  ~model_counters() {}

  //! Test method to print some counter information in endless loop.
  void printMessage();

  //! Stops the counters increase.
  void stopCounters();

  //! Continue the counters increase.
  void startCounters();

  //! Returns the counters' increase frequency, calculated by the rule:
  //! frequency = ((sum of counters)t1 + (sum of counters)t0) / (t1-t0).
  //! @return calculated frequency value.
  int getFrequency() const;

private:
  bool m_countersActive; //! state whether the counters are increased at the moment.
};
