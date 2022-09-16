#include "grains.h"

#include <iostream>

namespace grains {
constexpr int num_sqaures = 64;
ull_t lookup_table[num_sqaures] = {
    0,
};
ull_t square(int given) {
  if (given == 1) {
    if (!lookup_table[0]) lookup_table[0] = 1ULL;
    return lookup_table[0];
  }

  if (!lookup_table[given - 1]) {
    lookup_table[given - 1] = square(given - 1) * 2;
  }
  return lookup_table[given - 1];
}

ull_t total() {
  square(num_sqaures);

  ull_t sum = 0ULL;
  for (int i = 0; i < num_sqaures; ++i) {
    sum += lookup_table[i];
  }
  return sum;
}
}  // namespace grains
