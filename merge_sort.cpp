#include <iostream>
#include <vector>
#include <climits>

#include "sorting.hpp"
#include "utils.hpp"

using namespace std;

/**
 * Loop invariant:
 * At start of each iteration of the `for` loop of lines 1-8, the sub array
 * N[1..j-1] consists of the elements originally in N[1..j-1], but in sorted order.
 */

void merge(vector<int> & N, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for (int i = 0; i < n1; ++i) {
        L[i] = N[p + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = N[q + i + 1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

#ifndef NDEBUG
    cout << __func__ << " on N=";
    print_iterable(N, false);
    cout << "; L=";
    print_iterable(L, false);
    cout << "; R=";
    print_iterable(R, false);
    cout << "; p=" << p << "; q=" << q << "; r=" << r;
#endif

    int i = 0, j = 0;
    for (int k = p; k < r + 1; ++k) {
        if (L[i] < R[j]) {
            N[k] = L[i++];
        } else {
            N[k] = R[j++];
        }
    }

#ifndef NDEBUG
    cout << "->";
    print_iterable(N);
    cout << endl;
#endif
}

void merge_sort(vector<int> & N, int p, int r) {
    if (p < r) {

#ifndef NDEBUG
        cout << __func__ << " on ";
        print_iterable(N, false);
        cout << "; p=" << p << "; r=" << r << endl;
#endif

        int q = p + (r - p) / 2;
        merge_sort(N, p, q);
        merge_sort(N, q + 1, r);
        merge(N, p, q, r);
    }
}
