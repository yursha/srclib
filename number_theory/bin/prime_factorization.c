#include <stdio.h>  // printf
#include <stdlib.h> // free, strtoull

#include "../lib/prime_factorization.h"

// Performs prime factorization of an integer.
// The program takes ~30s to factorize the largest UINT64_T integer.
int main(int argc, char * args[]) {

  if (argc != 2) {
    printf("Usage: %s <number>\n", args[0]);
    return 1;
  }

  uint64_t number = strtoull(args[1], NULL, 10);

  struct vector factors = prime_factorization(number);
  if (factors.size == 0) {
    printf("prime\n");
  } else {
    for (int i = 0; i < factors.size; i++) {
      printf("%llu^%i ", factors.data[i].factor, factors.data[i].power);
    }
    printf("\n");
  }
  free(factors.data);
}
