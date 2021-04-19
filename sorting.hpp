#ifndef CLRS_SORTING
#define CLRS_SORTING

#include <vector>

void insertion_sort(std::vector<int> &);

void insertion_sort_nonincresing(std::vector<int> &);

void merge_sort(std::vector<int> & A, int p, int r);

void max_heapify(std::vector<int> & N, int i, int heap_size);

void heapsort_(std::vector<int> &);

void quicksort_(std::vector<int> & N, int lo, int hi);

void randomized_quicksort_(std::vector<int> & N, int lo, int hi);


#endif  // CLRS_SORTING
