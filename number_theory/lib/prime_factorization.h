#include <stdbool.h> // bool
#include <stdint.h> // uint*_t

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
  // The maximum value `size` can achieve is MAX_DISTINCT_FACTORS
  uint8_t size;
  struct factor* data;
};

// Caller must free `vector.data`.
struct vector prime_factorization(uint64_t n);
bool is_prime(uint64_t n);
