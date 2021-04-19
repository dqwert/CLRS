#include <iostream>
#include <vector>

#include "sorting.hpp"
#include "utils.hpp"

using namespace std;


int main() {
  vector<int> ivec {1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
  vector<int> ivec1 {1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
  vector<int> ivec2 {1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
  vector<int> ivec3 {1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
  vector<int> ivec4 {1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};

  cout << "reference solution: " << endl;
  sort(ivec.begin(), ivec.end());
  print_iterable(ivec);

  cout << "merge sort" << endl;
  merge_sort(ivec1, 0, int(ivec1.size() - 1));
  print_iterable(ivec1);

  cout << "heapsort" << endl;
  heapsort_(ivec2);
  print_iterable(ivec2);

  cout << "quicksort" << endl;
  quicksort_(ivec3, 0, int(ivec3.size()) - 1);
  print_iterable(ivec3);

  randomized_quicksort_(ivec4, 0, int(ivec4.size() - 1));
  print_iterable(ivec4);
}
