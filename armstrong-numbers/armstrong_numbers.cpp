#include "armstrong_numbers.h"

#include <cstddef>
#include <cstdint>
#include <string>

namespace armstrong_numbers {
static inline int64_t int_pow(int64_t base, size_t n) {
  int64_t ret = base;

  for (size_t i = 1UL; i < n; ++i) {
    ret *= base;
  }
  return ret;
}

bool is_armstrong_number(int num) {
  int64_t given = static_cast<int64_t>(num);
  size_t len = std::to_string(num).length();
  int64_t sum = 0;

  while (num > 0) {
    sum += int_pow(num % 10, len);
    num /= 10;
  }

  if (given == sum) return true;
  return false;
}
}  // namespace armstrong_numbers
