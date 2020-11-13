#include <assert.h> // assert
#include <stdio.h> // fflush, printf, stdout
#include <stdlib.h> // free, strtoull

#include "../lib/prime_factorization.h"

int main(int argc, char * args[]) {
  {
    uint64_t test_number = 2llu;
    printf("Testing %llu... ", test_number);
    fflush(stdout);
    struct vector factors = prime_factorization(test_number);
    assert(factors.size == 0);
    printf("OK\n");
  }
  {
    uint64_t test_number = 4llu;
    printf("Testing %llu... ", test_number);
    fflush(stdout);
    struct vector factors = prime_factorization(test_number);
    assert(factors.size == 1);

    assert(factors.data[0].factor == 2);
    assert(factors.data[0].power == 2);

    printf("OK\n");
  }
  {
    uint64_t test_number = UINT32_MAX;
    printf("Testing %llu... ", test_number);
    fflush(stdout);
    struct vector factors = prime_factorization(test_number);
    assert(factors.size == 5);

    assert(factors.data[0].factor == 3);
    assert(factors.data[0].power == 1);

    assert(factors.data[1].factor == 5);
    assert(factors.data[1].power == 1);

    assert(factors.data[2].factor == 17);
    assert(factors.data[2].power == 1);

    assert(factors.data[3].factor == 257);
    assert(factors.data[3].power == 1);

    assert(factors.data[4].factor == 65537);
    assert(factors.data[4].power == 1);

    printf("OK\n");
  }
  {
    uint64_t test_number = UINT64_MAX;
    printf("Testing %llu... ", test_number);
    fflush(stdout);
    struct vector factors = prime_factorization(test_number);
    assert(factors.size == 7);
    assert(factors.data[0].factor == 3);
    assert(factors.data[0].power == 1);

    assert(factors.data[1].factor == 5);
    assert(factors.data[1].power == 1);

    assert(factors.data[2].factor == 17);
    assert(factors.data[2].power == 1);

    assert(factors.data[3].factor == 257);
    assert(factors.data[3].power == 1);

    assert(factors.data[4].factor == 641);
    assert(factors.data[4].power == 1);

    assert(factors.data[5].factor == 65537);
    assert(factors.data[5].power == 1);

    assert(factors.data[6].factor == 6700417);
    assert(factors.data[6].power == 1);

    printf("OK\n");
  }
}
