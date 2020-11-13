#include "collision_probability.h"

long double collision_probability(uint64_t num_unique, uint64_t num_sampled) {
  long double result = 1;

  // Calculate the chance that there is no collision.
  while (--num_sampled > 0) {
    result *= (num_unique - num_sampled);
    result /= num_unique;
  }

  // Subtract from 100% to get the chance that there is at least once collision.
  return 1 - result;
}

