//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

// STL includes
#include <map>

typedef std::map<int, int> CountersMap; //!< typedef mapping integer to integer.

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

  //! Appendss a new counter.
  void addCounter();

  //! Removes the counter located at the specified position.
  //! Special value -1 removes the last element of the table.
  //! @param position the position in the container of counters.
  //! @return false if action failed.
  bool removeCounter(const int position);

  //! Returns the current model values.
  const CountersMap& getCounters() const { return m_counters; }

  //! Tests method to print some counter information in endless loop.
  void printMessage();

  //! Stops the counters increase.
  void stopCounters();

  //! Continues the counters increase.
  void startCounters();

  //! Returns the counters' increase frequency, calculated by the rule:
  //! frequency = ((sum of counters)t1 + (sum of counters)t0) / (t1-t0).
  //! @return calculated frequency value.
  int getFrequency() const;

  //! Returns the default value for inserted counters.
  static int defaultValue() { return 0; }

private:
  bool m_countersActive; //!< state whether the counters are increased at the moment.

  CountersMap m_counters; //!< container of values: a unique index to a value.
};
