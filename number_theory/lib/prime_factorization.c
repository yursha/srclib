#include <math.h> // sqrt
#include <stdlib.h> // malloc

#include "prime_factorization.h"

struct vector prime_factorization(uint64_t a) {
  struct vector v;
  v.size = 0;
  v.data = (struct factor*) malloc(sizeof(struct factor) * MAX_DISTINCT_FACTORS);

  // sqrt(UINT64_MAX) is not representable by uint32_t.
  // Hence the type of `bound` is `uint64_t`.
  //
  // UINT64_MAX = 18446744073709551615
  // sqrt(UNIT64_MAX) = 4294967296
  // UINT32_MAX = 4294967295
  uint64_t bound = (uint64_t) sqrt(a);

  for (uint64_t i = 2; i <= bound; i++) {
    struct factor f;
    f.factor = i;
    f.power = 0;
    while (a % i == 0) {
      f.power++;
      a /= i;
    }
    if (f.power > 0) {
      v.data[v.size++] = f;
    }
  }
  if (v.size && a != 1) {
    v.data[v.size].factor = a;
    v.data[v.size++].power = 1;
  }
  return v;
}

bool is_prime(uint64_t n) {
  return prime_factorization(n).size > 0;
}
