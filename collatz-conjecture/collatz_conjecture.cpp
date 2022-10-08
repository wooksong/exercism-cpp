#include "collatz_conjecture.h"

#include <stdexcept>

namespace collatz_conjecture {
int steps(int num) {
  int ret;
  if (num < 1) {
    throw std::domain_error("Invalid Argument: " + std::to_string(num));
  }

  ret = 0;
  while (num != 1) {
    if (num % 2 == 0) {
      num /= 2;
    } else {
      num *= 3;
      num += 1;
    }

    ret++;
  }

  return ret;
}
}  // namespace collatz_conjecture
