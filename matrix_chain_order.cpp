#include <iostream>
#include <vector>
#include <climits>

#include "dynamic_programming.hpp"
#include "utils.hpp"

void
matrix_chain_order(const std::vector<int> & p, std::vector<std::vector<int>> & m, std::vector<std::vector<int>> & s) {
  int n = (int) p.size() - 1;
  for (int i = 0; i < n; ++i) {
    m[i][i] = 0;
  }
  for (int l = 1; l < n; ++l) {
    for (int i = 1; i <= n - l; ++i) {
      int j = i + l;
      m[i - 1][j - 1] = INT_MAX;
      for (int k = i; k < j; ++k) {
        int q = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1] * p[k] * p[j];
        if (q < m[i - 1][j - 1]) {
          m[i - 1][j - 1] = q;
          s[i - 1][j - 1] = k;
        }
      }
    }
#ifndef NDEBUG
    std::cout << "m=" << std::endl;
    for (const auto & t : m) {
      print_iterable(t);
    }
    std::cout << "m=" << std::endl;
    std::cout << std::endl;
    for (const auto & t : s) {
      print_iterable(t);
    }
    std::cout << std::endl;
#endif
  }
}

void matrix_chain_order_print_optimal(const std::vector<int> & dimension) {
  int n = (int)dimension.size() - 1;
  std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));
  std::vector<std::vector<int>> s(n, std::vector<int>(n, 0));

  matrix_chain_order(dimension, m, s);
  std::cout << "m=" << std::endl;
  for (const auto & i : m) {
    print_iterable(i);
  }
  std::cout << "m=" << std::endl;
  for (const auto & i : s) {
    print_iterable(i);
  }
}
