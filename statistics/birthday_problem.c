// The problem is to compute an approximate probability that in a group of n people
// at least two have the same birthday.
//
// Let's compute the probability that no people from the group share a birthday.
// P(n) = 365/365 * 364/365 * ... * (365 - n)/365 = 365! / (365 - n)! * 365^n
//
// Probability that at least two people share a birthday is (1 - P(n)).
#include <float.h>
#include <stdio.h>

long double probability(n) {
  long double result = 1;
  while (--n > 0) {
    result *= (365 - n);
    result /= 365;
  }
  return 1 - result;
}

int main(int argc, char* args[]) {
  printf("Floating point precision used: %i\n", LDBL_DECIMAL_DIG);
  printf("P(%3i) = %.*Lf\n", 1, LDBL_DECIMAL_DIG - 1, probability(1));
  for (int i = 5; i <= 365; i += 5) {
    printf("P(%3i) = %.*Lf\n", i, LDBL_DECIMAL_DIG - 1, probability(i));
  }
}
