#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void print(const vector<int>& v) {
  cout << "[";
  for (int i : v) {
    cout << i << ",";
  }
  cout << "]" << endl;
}

// unstable
// O(n2)
void selection_sort(vector<int>& v) {
  for (int i = 0; i < v.size() - 1; i++) {
    int min = i;
    for (int j = i + 1; j < v.size(); j++) {
      if (v[min] > v[j]) min = j;
    }
    swap(v[i], v[min]);
  }
}

// stable
// O(n2)
void bubble_sort(vector<int>& v) {
  for (int i = v.size() - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (v[j] > v[j + 1]) swap(v[j], v[j + 1]);
    }
  }
}

// stable
// O(n2)
void insertion_sort(vector<int>& v) {
  for (int i = 1; i < v.size(); i++) {
    int n = v[i];
    int j = i - 1;
    while (v[j] > n) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = n;
  }
}

// stable
// O(nlogn)


// 2 4 6  1 3 5
// 1 4 6  2 3 5

void merge_sort(vector<int>& v) {
}

int main() {
  for (int i = 0; i < 100; i++) {

    vector<int> V;
    V.reserve(10);
    for (int j = 0; j < V.capacity(); j++) {
      V.push_back(rand() % 10);
    }
    cout << "Original:  ";
    print(V);

    auto V1 = V;
    selection_sort(V1);
    cout << "Selection: ";
    print(V1);

    auto V2 = V;
    bubble_sort(V2);
    cout << "Bubble:    ";
    print(V2);

    auto V3 = V;
    insertion_sort(V3);
    cout << "Insertion: ";
    print(V3);

    cout << endl;
  }
}
