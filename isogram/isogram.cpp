#include "isogram.h"

#include <string>
#include <vector>

namespace isogram {
bool is_isogram(const std::string phrase) {
  std::vector<bool> alphabets = std::vector<bool>(26, false);

  for (auto iter = phrase.begin(); iter != phrase.end(); ++iter) {
    size_t idx;

    if (*iter == '-' || *iter == ' ') continue;

    if (*iter >= 'a') {
      idx = static_cast<size_t>(*iter - 'a');
    } else if (*iter >= 'A') {
      idx = static_cast<size_t>(*iter - 'A');
    }

    if (alphabets[idx]) return false;
    alphabets[idx] = true;
  }
  return true;
}

}  // namespace isogram
