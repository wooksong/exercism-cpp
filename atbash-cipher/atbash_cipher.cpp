#include "atbash_cipher.h"

#include <iostream>
#include <string>

namespace atbash_cipher {
std::string encode(const std::string raw) {
    std::string encoded;
    int cnt = 0;

    for (auto iter = raw.begin(); iter != raw.end(); ++iter) {
        if (*iter == ' ' || *iter == ',' || *iter == '.')
            continue;

        if (cnt != 0 && cnt % 5 == 0) {
            encoded += ' ';
        }
        if ((*iter >= 'a' && *iter <= 'z') || (*iter >= 'A' && *iter <= 'Z')) {
            int idx;

            idx = static_cast<int>(*iter - 'a');
            idx = (idx >= 0 && idx < 26 ? idx : static_cast<int>(*iter - 'A'));
            encoded += static_cast<char>(static_cast<int>('z') - idx);
        } else {
            encoded += *iter;
        }

        cnt++;
    }

    return encoded;
}
std::string decode(const std::string encoded) {
    std::string decoded;

    for (auto iter = encoded.begin(); iter != encoded.end(); ++iter) {
        if (*iter == ' ')
            continue;

        if (*iter >= 'a' && *iter <= 'z') {
            decoded += ('z' - *iter + 'a');
        } else {
            decoded += *iter;
        }
    }

    return decoded;
}
} // namespace atbash_cipher
