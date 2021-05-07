#ifndef DYNAMIC_PROGRAMMING
#define DYNAMIC_PROGRAMMING

#include <vector>

int cut_rod_top_down_trivial(const std::vector<int> & price, int length);
int cut_rod_top_down_memoized(const std::vector<int> & price, int length);
int cut_rod_top_down_bottom_up(const std::vector<int> & price, int length);
int cut_rod_top_down_bottom_up_extended(const std::vector<int> & price, int length);

#endif //DYNAMIC_PROGRAMMING
