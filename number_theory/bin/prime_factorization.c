#include <stdio.h> // printf
#include <stdlib.h> // free, strtoull

#include "../lib/prime_factorization.h"

// Does a prime factorization of an integer.
// The program takes ~30s to factorize the largest UINT64_T integer.
int main(int argc, char * args[]) {

  if (argc != 2) {
    printf("Usage: %s <number>\n", args[0]);
    return 1;
  }

  uint64_t number = strtoull(args[1], NULL, 10);

  struct vector v = prime_factorization(number);
  if (v.size == 0) {
    printf("prime\n");
  } else {
    for (int i = 0; i < v.size; i++) {
      printf("%llu^%i ", v.data[i].factor, v.data[i].power);
    }
    printf("\n");
  }
  free(v.data);
}
