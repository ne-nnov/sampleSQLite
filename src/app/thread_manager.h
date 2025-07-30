//-----------------------------------------------------------------------------
// Created on: 30 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Qt includes

// STL includes
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

protected:
  //! Task to increase counters of the model.
  virtual void incrementCounters();

private:
  model_counters* m_model; //!< model to be modified by thread calls.
};
