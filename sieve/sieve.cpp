#include "sieve.h"

#include <bitset>
#include <vector>

namespace sieve {
constexpr size_t MAX_PRIME_N = 100000;

static std::bitset<MAX_PRIME_N> bitset_sieve(0x0UL);

std::vector<int> primes(int n) {
    std::vector<int> ret;

    if (bitset_sieve == 0x0UL) {
        bitset_sieve.set();
        bitset_sieve.reset(0);
        bitset_sieve.reset(1);

        for (size_t i = 2; i < MAX_PRIME_N; ++i) {
            for (size_t j = 2; i * j < MAX_PRIME_N; ++j) {
                bitset_sieve.reset(i * j);
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        if (bitset_sieve.test(i)) {
            ret.push_back(i);
        }
    }

    return ret;
}
} // namespace sieve
