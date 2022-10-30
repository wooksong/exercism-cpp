#include "binary.h"

#include <string>

namespace binary {
int convert(std::string num) {
  int ret = 0;
  int mul = 1;

  for (auto iter = num.rbegin(); iter != num.rend(); ++iter) {
    int n;

    if (*iter < '0' || *iter > '9') return 0;
    n = static_cast<int>(*iter - '0');
    ret += (n * mul);
    mul <<= 1;
  }

  return ret;
}
}  // namespace binary
