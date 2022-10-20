#include "pascals_triangle.h"

#include <iostream>
#include <vector>

namespace pascals_triangle {

constexpr int MAX_N = 32;

int calc_combination(int n, int r) {
  const int default_value = -1;
  const std::vector<int> v(MAX_N, default_value);
  static std::vector<std::vector<int>> dp(MAX_N, v);

  if (dp[n][r] == -1) {
    int val;

    if ((n == r) || (r == 0)) {
      val = 0;
      dp[n][r] = val;
    } else if ((r == 1) || (r == (n - 1))) {
      val = n;
    } else {
      val = calc_combination(n - 1, r - 1) + calc_combination(n - 1, r);
    }
    dp[n][r] = val;
  }

  return dp[n][r];
}

std::vector<std::vector<int>> generate_rows(int nrows) {
  std::vector<std::vector<int>> ret;

  for (int i = 0; i < nrows; ++i) {
    std::vector<int> each_row(i + 1);
    each_row[0] = 1;

    if (i > 0) {
      each_row[i] = 1;
    }
    ret.push_back(each_row);
  }
  for (int i = 1; i < nrows; ++i) {
    for (int j = 1; j < i; ++j) {
      ret[i][j] = calc_combination(i, j);
    }
  }
  return ret;
}
}  // namespace pascals_triangle
