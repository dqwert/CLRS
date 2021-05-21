#include <iostream>
#include <vector>
#include <climits>

#include "dynamic_programming.hpp"
#include "utils.hpp"


int cut_rod_top_down_trivial(const std::vector<int> & price, int length) {
  if (length == 0) {
    return 0;
  }
  int profit = INT_MIN;
  for (int cut = 1; cut <= length; ++cut) {
#ifndef NDEBUG
    PRINT_VAL(cut);
    PRINT_VAL(profit);
    printf("\n");
#endif
    profit = std::max(profit, price[cut - 1] + cut_rod_top_down_trivial(price, length - cut));
  }

  return profit;
}

int cut_rod_top_down_memoized_helper(const std::vector<int> & price, int length, std::vector<int> & revenue) {
  if (revenue[length] >= 0) { return revenue[length]; }
  int profit = INT_MIN;
  for (int cut = 1; cut <= length; ++cut) {
    profit = std::max(profit, price[cut - 1] + cut_rod_top_down_memoized_helper(price, length - cut, revenue));
  }
  revenue[length] = profit;
  return profit;
}

int cut_rod_top_down_memoized(const std::vector<int> & price, int length) {
  std::vector<int> revenue(price.size() + 1, INT_MIN);
  revenue[0] = 0;
  return cut_rod_top_down_memoized_helper(price, length, revenue);
}

int cut_rod_top_down_bottom_up(const std::vector<int> & price, int length) {
  std::vector<int> revenue(price.size() + 1, INT_MIN);
  revenue[0] = 0;

  for (int len = 1; len <= length; ++len) {
    int profit = INT_MIN;
    for (int cut = 1; cut <= len; ++cut) {
#ifndef NDEBUG
      printf("len=%d, cut=%d, price of cut=%d, revenue of rest=%d;\n", len, cut, price[cut - 1], revenue[len - cut]);
#endif
      profit = std::max(profit, price[cut - 1] + revenue[len - cut]);
    }
    revenue[len] = profit;
  }
  return revenue[length];
}

int cut_rod_top_down_bottom_up_extended(const std::vector<int> & price, int length) {
  std::vector<int> revenue(price.size() + 1, INT_MIN);
  std::vector<int> cuts(price.size());
  revenue[0] = 0;

  for (int len = 1; len <= length; ++len) {
    int profit = INT_MIN;
    for (int cut = 1; cut <= len; ++cut) {
#ifndef NDEBUG
      printf("len=%d, cut=%d, price of cut=%d, revenue of rest=%d;\n", len, cut, price[cut - 1], revenue[len - cut]);
#endif
      if (price[cut - 1] + revenue[len - cut] > profit) {
        profit = price[cut - 1] + revenue[len - cut];
        cuts[len - 1] = cut;
      }
    }
    revenue[len] = profit;
  }

  printf("solution: ");
  int len = length;
  while (len) {
    printf("%i, ", cuts[len - 1]);
    len -= cuts[len - 1];
  }
  printf("\n");

  return revenue[length];
}

int cut_rod_top_down_cost(const std::vector<int> & price, int length, int cost) {
  std::vector<int> revenue(price.size() + 1, INT_MIN);
  revenue[0] = 0;

  for (int len = 1; len <= length; ++len) {
    int profit = INT_MIN;
    for (int cut = 1; cut <= len; ++cut) {
#ifndef NDEBUG
      printf("len=%d, cut=%d, price of cut=%d, revenue of rest=%d;\n", len, cut, price[cut - 1], revenue[len - cut]);
#endif
      profit = std::max(profit, price[cut - 1] + revenue[len - cut] - cost);
    }
    revenue[len] = profit;
  }
  return revenue[length];
}

int fibonacci(int n) {
  if (n == 0) { return 0; }
  int a = 0, b = 1, c = -1;
  while (n > 1) {
    c = a + b;
    a = b;
    b = c;
    --n;
  }
  return b;
}