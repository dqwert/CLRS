#ifndef DYNAMIC_PROGRAMMING
#define DYNAMIC_PROGRAMMING

#include <vector>

int cut_rod_top_down_trivial(const std::vector<int> & price, int length);
int cut_rod_top_down_memoized(const std::vector<int> & price, int length);
int cut_rod_top_down_bottom_up(const std::vector<int> & price, int length);
int cut_rod_top_down_bottom_up_extended(const std::vector<int> & price, int length);
int cut_rod_top_down_cost(const std::vector<int> & price, int length, int cost);

int fibonacci(int n);

void matrix_chain_order(const std::vector<int> & p, std::vector<std::vector<int>> & m, std::vector<std::vector<int>> & s);
void matrix_chain_order_print_optimal(const std::vector<int> & dimension);

#endif //DYNAMIC_PROGRAMMING
