#include <assert.h> // assert
#include <stdio.h>  // fflush, printf

#include "../lib/collision_probability.h"

void assert_probability(
      uint64_t domain_size, uint64_t sample_size, long double expected_p) {
    printf("Testing sample of %llu from domain of %llu... ", sample_size, domain_size);
    fflush(stdout);
    long double p = collision_probability(domain_size, sample_size);
    assert(p == expected_p);
    printf("OK\n");
}

int main(int argc, char* args[]) {
  assert_probability(365, 15, 0.25290131976368637198L);
}

