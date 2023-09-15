#include "nth_prime.h"

#include <bitset>
#include <stdexcept>

namespace nth_prime {
constexpr int MAX_NTH = 200000;

static bool is_initialized = false;
static std::bitset<MAX_NTH> sieve;

int nth(int ordinal) {
    int ret;

    if (ordinal == 0) {
        throw std::domain_error("");
    }

    if (!is_initialized) {
        sieve.set();
        sieve.reset(0);
        sieve.reset(1);

        for (int i = 2; i < MAX_NTH; ++i) {
            for (int j = 2; i * j < MAX_NTH; ++j) {
                sieve.reset(i * j);
            }
        }
        is_initialized = true;
    }

    ret = 0;
    for (int i = 0; ret < MAX_NTH; ++ret) {
        if (sieve.test(ret)) {
            ++i;
            if (i == ordinal) {
                break;
            }
        }
    }
    return ret;
}

} // namespace nth_prime
