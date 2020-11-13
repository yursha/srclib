#include <math.h>   // sqrt
#include <stdlib.h> // malloc

#include "prime_factorization.h"

struct vector prime_factorization(uint64_t n) {
  struct vector factors;
  factors.size = 0;
  factors.data = (struct factor*) malloc(sizeof(struct factor) * MAX_DISTINCT_FACTORS);

  // sqrt(UINT64_MAX) is not representable by uint32_t.
  // Hence the type of `bound` is `uint64_t`.
  //
  // UINT64_MAX = 18446744073709551615
  // sqrt(UNIT64_MAX) = 4294967296
  // UINT32_MAX = 4294967295
  uint64_t bound = (uint64_t) sqrt(n);

  for (uint64_t i = 2; i <= bound; i++) {
    struct factor f;
    f.factor = i;
    f.power = 0;
    while (n % i == 0) {
      f.power++;
      n /= i;
    }
    if (f.power > 0) {
      factors.data[factors.size++] = f;
    }
  }
  if (factors.size && n != 1) {
    factors.data[factors.size].factor = n;
    factors.data[factors.size++].power = 1;
  }
  return factors;
}

bool is_prime(uint64_t n) {
  return prime_factorization(n).size > 0;
}
