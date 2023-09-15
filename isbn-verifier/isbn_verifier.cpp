#include "isbn_verifier.h"

#include <string>

namespace isbn_verifier {
    bool is_valid(const std::string &isbn) {
        constexpr int64_t mul = 10;
        constexpr int64_t mod = 11;
        int64_t isbn_as_num = 0;
        size_t len = 0;
        int i = mul;

        for (const char &c : isbn) {
            int64_t v;

            if (c == '-')
                continue;

            len++;
            if (c == 'X') {
                if (len != 10)
                    return false;
                v = 10;
            } else {
                v = static_cast<int64_t>(c - '0');
            }

            isbn_as_num += (v * (i--));
        }

        if (len != 10 || (isbn_as_num % mod) != 0)
            return false;
        return true;
    }

    bool is_valid(const char *isbn) {
        return is_valid(std::string(isbn));
    }
}  // namespace isbn_verifier
