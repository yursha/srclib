#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// Expected to print 66.6%
int main() {
  srand(time(nullptr));

  int the_greater_of_two_is_the_greater_of_three = 0;
  int num_experiments = 1000;
  for (int i = 0; i < num_experiments; i++) {
    int a = rand() % 100;
    int b = rand() % 100;
    int c = rand() % 100;

    int g = a > b ? a : b;
    if (g > c) the_greater_of_two_is_the_greater_of_three++;
  }

  cout << 100.0 * the_greater_of_two_is_the_greater_of_three / num_experiments << endl;
}
