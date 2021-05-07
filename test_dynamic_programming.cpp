#include <iostream>
#include <vector>

#include "dynamic_programming.hpp"
#include "utils.hpp"

using namespace std;

int main() {
  vector<int> price {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
  print_iterable(price);

  for (int i = 1; i <= (int) price.size(); ++i) {
    printf("%i\n", cut_rod_top_down_trivial(price, i));
    printf("%i\n", cut_rod_top_down_memoized(price, i));
    printf("%i\n", cut_rod_top_down_bottom_up(price, i));
    printf("%i\n", cut_rod_top_down_bottom_up_extended(price, i));
  }
}
