#include "acronym.h"

#include <string>

namespace acronym {
std::string acronym(std::string phrase) {
  std::string acronym = "";
  std::string word = "";

  for (auto iter = phrase.begin(); iter != phrase.end(); ++iter) {
    if (word.length() > 0 &&
        ((iter + 1 == phrase.end()) || *iter == ' ' || *iter == '-')) {
      char letter = word[0];

      if (letter >= 'a' && letter <= 'z') {
        letter = 'A' + letter - 'a';
      }
      acronym += letter;
      word = "";
      continue;
    }

    word += (*iter);
  }

  return acronym;
}

}  // namespace acronym
