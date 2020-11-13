#include <stdint.h>

// Computes a chance of at least one collision (eaual value) when we sample
// `num_sampled` values in the domain of size `num_unique`.
//
// This is a general case of a Birthday Problem.
long double collision_probability(uint64_t num_unique, uint64_t num_sampled);
