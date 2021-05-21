#include <iostream>
#include <vector>

#include "dynamic_programming.hpp"
#include "utils.hpp"

using namespace std;

int main() {
//  vector<int> price {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//  print_iterable(price);
//
//  for (int i = 1; i <= (int) price.size(); ++i) {
//    cout << "i=i\t" << cut_rod_top_down_trivial(price, i) << ", " << cut_rod_top_down_memoized(price, i) << ", " << cut_rod_top_down_bottom_up(price, i) << ", " << cut_rod_top_down_bottom_up_extended(price, i) << ", " << cut_rod_top_down_cost(price, i, 1) << endl;
//  }
//
//  cout << "fibonacci" << endl;
//  for (int i = 0; i < 30; ++i) {
//    cout << "fib(" << i << ")=" << fibonacci(i) << ", " << endl;
//  }

//  cout << "matrix_chain_order" << endl;
  vector<int> dimension{5, 10, 3, 12, 5, 50, 6};
  matrix_chain_order_print_optimal(dimension);
}
