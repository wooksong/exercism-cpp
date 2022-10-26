#include "sum_of_multiples.h"

#include <iostream>
#include <unordered_map>
#include <vector>

namespace sum_of_multiples {
int to(const std::vector<int> nums, int yield) {
    std::unordered_map<int, int> dict;
    int sum = 0;
    int num;

    for (size_t i = 0; i < nums.size(); ++i) {
        int mul = nums[i];

        num = 0;
        for (int j = 1; num < yield; ++j) {
            num = (mul * j);

            if (num >= yield) {
                break;
            } else if (dict.find(num) == dict.end()) {
                dict[num] = 1;
                sum += num;
            } else {
                ++dict[num];
            }
        }
    }

    return sum;
}
} // namespace sum_of_multiples
