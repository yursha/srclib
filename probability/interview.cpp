/*
Your department decides to interview three qualified candidates
(Ames, Boyd, and Clark), in an arbitrary order, for a junior faculty
opening. After Ames and Clark have visited, the faculty meet and
agree on the following: (1) before interviewing any candidates there
was no consensus concerning who was strongest; (2) after seeing
Ames and Clark, Ames was judged to be stronger than Clark; (3) if,
on the basis of (1) and (2), there is at least a 60 percent chance that
Ames is the strongest of the three candidates, the department will
make an immediate offer to Ames. What is your best estimate of the
probability that Ames is the strongest of the three candidates, given
that Ames is stronger than Clark?

Fox, Craig & Levav, Jonathan. (2005). Partition-Edit-Count: Naive Extensional Reasoning in Judgment of Conditional Probability. Journal of experimental psychology. General. 133. 626-42. 10.1037/0096-3445.133.4.626. 
*/

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
