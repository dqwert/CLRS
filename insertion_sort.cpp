#include <vector>

#include "sorting.hpp"
#include "utils.hpp"

using namespace std;

/**
 * Loop invariant:
 * At start of each iteration of the `for` loop of lines 1-8, the sub array
 * A[1..j-1] consists of the elements originally in A[1..j-1], but in sorted order.
 */

void insertion_sort(vector<int> & N) {
  print_debug_info(__func__, N);

  for (int j = 1; j < N.size(); ++j) {
    int key = N[j];
    int i = j - 1;
    while (i >= 0 && N[i] > key) {
      N[i + 1] = N[i];
      --i;

      print_debug_info(__func__, N);
    }
    N[i + 1] = key;
  }
}

void insertion_sort_non_increasing(vector<int> & N) {
  print_debug_info(__func__, N);

  for (int j = 1; j < N.size(); ++j) {
    int key = N[j];
    int i = j - 1;
    while (i >= 0 && N[i] < key) {
      N[i + 1] = N[i];
      --i;

      print_debug_info(__func__, N);
    }
    N[i + 1] = key;
  }
}
