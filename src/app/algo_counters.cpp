//-----------------------------------------------------------------------------
// Created on: 31 July 2025
// Author: Natalia Ermolaeva
//-----------------------------------------------------------------------------

// Own includes
#include <algo_counters.h>

// STL includes
#include <numeric>

//-----------------------------------------------------------------------------
double algo_counters::arithmeticSum(const CountersMap& values)
{
  return std::accumulate(values.begin(), values.end(), 0);
}

