//-----------------------------------------------------------------------------
// Created on: 31 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

#pragma once

// model includes
#include "model_counters.h"

//! Provides counter-related algorithms.
class algo_counters
{
public:
  //! Computes the arithmetic sum.
  //! @param values container of values.
  //! @return sum of values.
  static double arithmeticSum(const CountersMap& values);
};
