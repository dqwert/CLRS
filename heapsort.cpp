#include <iostream>
#include <vector>
#include <climits>

#include "sorting.hpp"
#include "utils.hpp"

inline int parent(int i) { return (i + 1) / 2 - 1; }
inline int left(int i) { return i * 2 + 1; }
inline int right(int i) { return 2 * i + 2; }


void max_heapify(std::vector<int> & N, int i, int heap_size) {
    int l = left(i);
    int r = right(i);

    int largest = i;
    if (l < N.size() && N[l] > N[i]) {
        largest = l;
    }
    if (r < N.size() && N[r] > N[largest]) {
        largest = r;
    }

#ifndef NDEBUG
    mprint(i);
    mprint(l);
    mprint(r);
    mprint(largest);
    std::cout << std::endl;
#endif

    if (largest != i) {

#ifndef NDEBUG
    std::cout << "Swap a[" << i << "] and N[" << largest << "]. " << std::endl;
#endif

        std::swap(N[i], N[largest]);
        max_heapify(N, largest, heap_size);
    }
}

void build_max_heap(std::vector<int> & N) {
    for (int i = N.size() / 2 - 1; i >= 0; --i) {
        max_heapify(N, i, N.size());
    }
}

void heapsort_(std::vector<int> & N) {
    build_max_heap(N);

    int heap_size = N.size();
    for (int i = N.size(); i >= 1; --i) {
        std::swap(N[1], N[i]);
        max_heapify(N, 1, --heap_size);
        print_iterable(N);
    }

}

