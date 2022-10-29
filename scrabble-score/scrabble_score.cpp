#include "scrabble_score.h"

#include <string>
#include <unordered_map>

namespace scrabble_score {
static const std::unordered_map<char, int> letter_values = {
    {'A', 1}, {'E', 1}, {'I', 1}, {'O', 1},  {'U', 1},  {'L', 1}, {'N', 1},
    {'R', 1}, {'S', 1}, {'T', 1}, {'D', 2},  {'G', 2},  {'B', 3}, {'C', 3},
    {'M', 3}, {'P', 3}, {'F', 4}, {'H', 4},  {'V', 4},  {'W', 4}, {'Y', 4},
    {'K', 5}, {'J', 8}, {'X', 8}, {'Q', 10}, {'Z', 10},
};
int score(std::string s) {
  int ret = 0;

  for (char c : s) {
    if (c >= 'a' && c <= 'z') {
      c = c - 'a' + 'A';
    }

    if (letter_values.find(c) != letter_values.end()) {
      ret += letter_values.at(c);
    }
  }

  return ret;
}
}  // namespace scrabble_score
