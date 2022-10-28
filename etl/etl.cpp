#include "etl.h"

#include <map>
#include <vector>

namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>> old) {
    std::map<char, int> ret;

    for (auto iter = old.begin(); iter != old.end(); ++iter) {
        std::vector<char> letters = iter->second;
        int score = iter->first;

        for (char letter : letters) {
            ret['a' + (letter - 'A')] = score;
        }
    }

    return ret;
}

} // namespace etl
