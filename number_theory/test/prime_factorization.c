#include <assert.h> // assert
#include <stdio.h>  // fflush, printf, stdout
#include <stdlib.h> // free, strtoull

#include "../lib/prime_factorization.h"

void assert_factors(uint64_t test_number, size_t num_factors,
                    uint64_t expected_factors[]) {
    printf("Testing %llu... ", test_number);
    fflush(stdout);
    struct vector factors = prime_factorization(test_number);
    assert(factors.size == num_factors);

    for (int i = 0; i < num_factors; i++) {
      assert(factors.data[i].factor == expected_factors[i * 2]);
      assert(factors.data[i].power == expected_factors[i * 2 + 1]);
    }

    printf("OK\n");
}

int main(int argc, char * args[]) {
  assert_factors(2, 0, (uint64_t[]){});
  assert_factors(4, 1, (uint64_t[]){2, 2});
  assert_factors(UINT32_MAX, 5, (uint64_t[]){3, 1, 5, 1, 17, 1, 257, 1, 65537, 1});
  assert_factors(UINT64_MAX, 7,
      (uint64_t[]){3, 1, 5, 1, 17, 1, 257, 1, 641, 1, 65537, 1, 6700417, 1});
}
