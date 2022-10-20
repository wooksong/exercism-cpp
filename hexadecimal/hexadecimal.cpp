#include "hexadecimal.h"

#include <string>

namespace hexadecimal {
int convert(const std::string hexstr) {
  int ret = 0;
  int mul = 1;

  for (auto iter = hexstr.rbegin(); iter != hexstr.rend(); ++iter, mul *= 16) {
    if (*iter >= 'a' && *iter <= 'f') {
      ret += (static_cast<int>(*iter - 'a' + 10) * mul);
    } else if (*iter >= '0' && *iter <= '9') {
      ret += (static_cast<int>(*iter - '0') * mul);
    } else {
      ret = 0;
      break;
    }
  }

  return ret;
}
}  // namespace hexadecimal
