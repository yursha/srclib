#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// UINT64_MAX = 1.844674e+19
// 21! = 5.1090942e+19 > UINT64_MAx
// Therefore, the upper theoretical bound on the number of distinct factors is 21.
#define MAX_DISTINCT_FACTORS 21

struct factor {
  uint64_t factor;

  // The highest representable value of uint64_t = 2^64.
  // Therefore 64 is the greatest value of `power`, since
  // 2 is the smallest possible factor.
  // Regardless, `power` is likely to be aligned on an 8-byte boundary.
  uint8_t power;
};

struct vector {
  // The maximum value `n` can achieve is MAX_DISTINCT_FACTORS
  uint8_t n;
  struct factor* data;
};

struct vector prime_factorization(uint64_t a) {
  struct vector v;
  v.n = 0;
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
      v.data[v.n++] = f;
    }
  }
  if (v.n && a != 1) {
    v.data[v.n].factor = a;
    v.data[v.n++].power = 1;
  }
  return v;
}

// Does a prime factorization of an integer.
// The program takes ~30s to factorize the largest UINT64_T integer.
int main(int argc, char * args[]) {

  if (argc != 2) {
    printf("Usage: %s <number>\n", args[0]);
    return 1;
  }

  uint64_t number = strtoull(args[1], NULL, 10);

  struct vector v = prime_factorization(number);
  if (v.n == 0) {
    printf("%llu is a prime number!\n", number);
  } else {
    printf("factors of %llu are: ", number);
    for (int i = 0; i < v.n; i++) {
      printf("%llu^%i ", v.data[i].factor, v.data[i].power);
    }
    printf("\n");
  }
  free(v.data);
}
