#include "matching_brackets.h"

#include <string>
#include <vector>

namespace matching_brackets {
bool check(std::string s) {
    std::vector<char> stack;
    char pair;

    stack.reserve(s.size());
    for (auto iter = s.begin(); iter != s.end(); ++iter) {
        pair = ' ';
        switch (*iter) {
        case '(':
        case '{':
        case '[':
            stack.push_back(*iter);
            break;
        case ')':
            pair = '(';
            break;
        case '}':
            pair = '{';
            break;
        case ']':
            pair = '[';
            break;
        default:
            break;
        }

        if (pair == ' ') {
            continue;
        }

        if (pair != stack.back()) {
            return false;
        }
        stack.pop_back();
    }
    return stack.empty();
}
} // namespace matching_brackets
