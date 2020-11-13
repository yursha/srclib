#include <assert.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h> // strtoull

#include "../lib/collision_probability.h"

// Prints probabilities of a collision when choosing (with repetition) N
// out of `num_unique` numbers. N is initialized with 2 and incremented by
// `step` until either `num_unique` is reached or the estimated probability
// equals 1 because of the limitations of `long double` FP precision.
// For each N, a probability is printed.
int main(int argc, char* args[]) {
  if (argc != 3) {
    printf("Usage: %s <num_unique> <step>\n", args[0]);
    return 1;
  }

  uint64_t num_unique = strtoull(args[1], NULL, 10);
  uint64_t step = strtoull(args[2], NULL, 10);

  int sample_size = 2;

  printf("P(%i) = %.*Lf\n", sample_size, LDBL_DECIMAL_DIG - 1,
      collision_probability(num_unique, 2));
  for (sample_size = step; sample_size <= num_unique; sample_size += step) {
    if (sample_size == 2) continue; // already printed above
    long double probability = collision_probability(num_unique, sample_size);
    printf("P(%i) = %.*Lf\n", sample_size, LDBL_DECIMAL_DIG - 1, probability);
    if ((int) probability == 1) break;
  }
}
