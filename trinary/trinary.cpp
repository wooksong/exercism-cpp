#include "trinary.h"

namespace trinary {
int to_decimal(const std::string s) {
    int ret = 0;
    int mul = 1;

    for (auto iter = s.rbegin(); iter != s.rend(); ++iter) {
        if (!(*iter >= '0' && *iter <= '2')) {
            ret = 0;
            break;
        }
        ret += (static_cast<int>(*iter - '0') * mul);
        mul *= 3;
    }

    return ret;
}
} // namespace trinary
