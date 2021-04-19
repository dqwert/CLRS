#include <iostream>
#include <vector>
#include <climits>

#include "dynamic_programming.hpp"
#include "utils.hpp"


int cut_rod_top_down_trivial(std::vector<int> price, int length) {
  if (length == 0) {
    return 0;
  }
  int max_profit = INT_MIN;
  for (int i = 0; i < price.size(); ++i) {
    max_profit = std::max(max_profit,
                          price[i] + cut_rod_top_down_trivial(price, length - i));
  }

#ifndef NDEBUG
  PRINT_VAL(max_profit);
#endif

  return max_profit;
}

