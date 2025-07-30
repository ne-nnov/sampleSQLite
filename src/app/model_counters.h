//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

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
};
