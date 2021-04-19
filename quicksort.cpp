#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#include "sorting.hpp"
#include "utils.hpp"

using namespace std;


int partition(vector<int> & N, int lo, int hi) {
  int x = N[hi];
  int i = lo - 1;
  for (int j = lo; j < hi; ++j) {
    if (N[j] <= x) {
      swap(N[++i], N[j]);

      print_debug_info(__func__, N);
    }
  }
  swap(N[++i], N[hi]);
  print_debug_info(__func__, N);
  return i;
}


void quicksort_(vector<int> & N, int lo, int hi) {
  if (lo < hi) {
    int pivot = partition(N, lo, hi);
    quicksort_(N, lo, pivot - 1);
    quicksort_(N, pivot, hi);
  }
}


int randomized_partition(vector<int> & N, int lo, int hi) {
  int i = lo + int(random() % (hi - lo + 1));
  swap(N[hi], N[i]);
  return partition(N, lo, hi);
}

void randomized_quicksort_(vector<int> & N, int lo, int hi) {
  if (lo < hi) {
    int pivot = randomized_partition(N, lo, hi);
    randomized_quicksort_(N, lo, pivot - 1);
    randomized_quicksort_(N, pivot, hi);
  }
}