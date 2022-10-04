#include "hamming.h"

#include <iostream>

namespace hamming {
int compute(const std::string &lhs, const std::string &rhs) {
  int cnt;

  if (lhs.length() != rhs.length()) {
    throw std::domain_error(
        "Cannot calculate Hamming Distance between sequences of different "
        "lengths");
  }

  cnt = 0;
  for (size_t i = 0; i < lhs.length(); ++i) {
    if (lhs[i] != rhs[i]) cnt++;
  }
  return cnt;
}
}  // namespace hamming
