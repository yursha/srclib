#include <stdint.h>

// Given `num_sampled` randomly generated values,
//  where each value is a non-negative integer
// less than `num_unique`, what is the probability that at least two of them are equal.
//
// This is a general case of a Birthday Problem.
long double collision_probability(uint64_t num_unique, uint64_t num_sampled);
