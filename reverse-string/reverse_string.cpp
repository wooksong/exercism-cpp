#include "reverse_string.h"

namespace reverse_string {
std::string reverse_string(const std::string str) {
  std::string ret;

  for (auto iter = str.rbegin(); iter != str.rend(); ++iter) {
    ret.append(1, *iter);
  }

  return ret;
}

}  // namespace reverse_string
