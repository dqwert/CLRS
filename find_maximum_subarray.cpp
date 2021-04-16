// chapter 4 devide and conquer
#include <iostream>
#include <vector>
#include <climits>
#include <chrono>
#include <cstdlib>

#include "utils.hpp"

using namespace std;

void find_max_crossing_subarray(const vector<int> & N, int low, int mid, int high,
                                // return:
                                int & max_left, int & max_right, int & sum) {
    if (N.size() == 0) {
        return;
    }

    int left_sum = INT_MIN;
    int curr_sum = 0;
    for (int i = mid; i > low; --i) {
        curr_sum += N[i];
        if (curr_sum > left_sum) {
            left_sum = curr_sum;
            max_left = i;
        }
    }

    int right_sum = INT_MIN;
    curr_sum = 0;
    for (int j = mid + 1; j < high; ++j) {
        curr_sum += N[j];
        if (curr_sum > right_sum) {
            right_sum = curr_sum;
            max_right = j;
        }
    }

    sum = left_sum + right_sum;
}

void find_maximum_subarray(const vector<int> & N, int low, int high,
                           // return:
                           int & max_left, int & max_right, int & sum) {
    if (low == high) {
        max_left = low;
        max_right = high;
        sum = N[low];
        return;
    }

    int mid = low + (high - low) / 2;

    int left_low, left_high, left_sum;
    int right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum;

    find_maximum_subarray(N, low, mid, left_low, left_high, left_sum);
    find_maximum_subarray(N, mid + 1, high, right_low, right_high, right_sum);
    find_max_crossing_subarray(N, low, mid, high, cross_low, cross_high, cross_sum);

    if (left_sum >= right_sum && left_sum >= cross_sum) {
        max_left = left_low;
        max_right = left_high;
        sum = left_sum;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        max_left = right_low;
        max_right = right_high;
        sum = right_sum;
    } else {
        max_left = cross_low;
        max_right = cross_high;
        sum = cross_sum;
    }
    mprint(max_left);
    mprint(max_right);
    mprint(sum);
    cout << endl;
}

void find_maximum_subarray_brutal_force(const vector<int> & N, int low, int high,
                                        // return:
                                        int & max_left, int & max_right, int & sum) {
    int max_sum = INT_MIN;
    int n = N.size();
    for (int i = 0; i < n; ++i) {
        int curr_sum = 0;
        for (int j = i; j < n; ++j) {
            curr_sum += N[j];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_left = i;
                max_right = j;
            }
        }
    }
}

int main() {
    // init vevtor
    // vector<int> N = {13, -3, -25, 20 -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    vector<int> N;
    init_random_vector(N, 100);
    cout << N.size() << " ";
    print_iterable(N);
    cout << endl;

    // init variable passed by refrence
    int max_left, max_right, sum;
    
    // divide and conquer
    auto start = chrono::high_resolution_clock::now();
    find_maximum_subarray(N, 0, N.size() / 16, max_left, max_right, sum);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cout << "time elapsed=" << duration.count() << endl; 

    mprint(max_left);
    mprint(max_right);
    mprint(sum);
    cout << endl;

    // brutal force
    start = chrono::high_resolution_clock::now();
    find_maximum_subarray_brutal_force(N, 0, N.size(), max_left, max_right, sum);
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(stop - start); 
    cout << "time elapsed=" << duration.count() << endl; 
    
    mprint(max_left);
    mprint(max_right);
    mprint(sum);
    cout << endl;
    
    return 0;
}
