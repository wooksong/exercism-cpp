#include "luhn.h"

#include <iostream>
#include <string>

namespace luhn {
bool valid(std::string s) {
  int idx = 1;
  int num = 0;

  for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
    int each;

    if (*iter == ' ') continue;
    if (*iter < '0' || *iter > '9') return false;

    each = static_cast<int>(*iter - '0');

    if (idx % 2 == 0) {
      each *= 2;
      if (each > 9) {
        each -= 9;
      }
    }
    num += each;
    idx++;
  }

  if ((idx - 1) < 2 || num % 10 != 0) return false;
  return true;
}
}  // namespace luhn
