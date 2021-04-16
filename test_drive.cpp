#include <iostream>
#include <vector>

#include "sorting.hpp"
#include "utils.hpp"

using namespace std;

int main() {
    vector<int> ivec {1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
    vector<int> ivec2{1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
    vector<int> ivec3{1, 4, 5, 6, 7, 2, 3, 0, -2, 4234, 32, 13, 42, 23, -324};
    vector<int> ivec4{16, 4, 10, 14, 7, 9, 3, 2, 8, 1};

    
    // merge_sort(ivec, 0, ivec.size() - 1);
    // print_iterable(ivec);

    // heapsort_(ivec);
    // print_iterable(ivec);

    sort(ivec.begin(), ivec.end());
    print_iterable(ivec);

    quicksort_(ivec2, 0, ivec2.size() - 1);
    print_iterable(ivec2);

    randomized_quicksort_(ivec3, 0, ivec3.size() - 1);
    print_iterable(ivec3);
}
