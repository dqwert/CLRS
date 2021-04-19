#ifndef CLRS_UTILS
#define CLRS_UTILS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

#define PRINT_VAL(a) \
    do { std::cout << #a "=" << (a) << "; "; } while (false)

template<typename T>
void print_iterable(const T & t, bool newline = true) {
  std::cout << "{";
  for (auto i : t) {
    std::cout << i << ", ";
  }
  if (newline) {
    std::cout << "\b\b}\n";
  } else {
    std::cout << "\b\b}";
  }
}


inline void print_debug_info(const std::string & func_name, const std::vector<int> & ivec = {}) {
#ifndef NDEBUG
  std::cout << func_name << std::endl;
  if (!ivec.empty()) {
      std::cout << "\toperates on: ";
      print_iterable(ivec);
  }
#endif
}


inline void init_random_vector(std::vector<int> & N, int size = 20) {
  srandom(42);
  while (size--) {
    N.push_back(int(random()) % 100 * (int(random()) % 2 == 0 ? 1 : -1));
  }
}

#endif  // CLRS_UTILS
