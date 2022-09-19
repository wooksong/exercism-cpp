#include "pangram.h"

#include <string>

namespace pangram {
bool is_pangram(const std::string s) {
  const static int NUM_ALPHABET = 26;
  int alphabet_table[NUM_ALPHABET] = {
      0,
  };

  for (auto iter = s.begin(); iter != s.end(); ++iter) {
    int idx;

    if (*iter >= 'A' && *iter <= 'Z') {
      idx = *iter - 'A';
    } else if (*iter >= 'a' && *iter <= 'z') {
      idx = *iter - 'a';
    } else {
      continue;
    }

    alphabet_table[idx]++;
  }

  for (int i = 0; i < NUM_ALPHABET; ++i) {
    if (alphabet_table[i] == 0) {
      return false;
    }
  }

  return true;
}

}  // namespace pangram
