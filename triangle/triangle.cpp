#include "triangle.h"

#include <iostream>

namespace triangle {
flavor kind(double side_first, double side_second, double side_third) {
  double first_and_second = side_first + side_second;
  double second_and_third = side_second + side_third;
  double first_and_third = side_first + side_third;

  if (side_first <= 0 || side_second <= 0 || side_third <= 0) {
    throw std::domain_error(
        "At least one of the given lengths is negative or zero.");
  }

  if (first_and_second < side_third || second_and_third < side_first ||
      first_and_third < side_second) {
    throw std::domain_error(
        "A sum of any two sides' lengths should be greater than or equal to "
        "the length of the third side in triangle");
  }

  if ((side_first == side_second) && (side_first == side_third)) {
    return flavor::equilateral;
  }

  if (side_first == side_second || side_second == side_third ||
      side_first == side_third) {
    return flavor::isosceles;
  }

  if ((side_first != side_second) && (side_second != side_third) &&
      (side_first != side_third)) {
    return flavor::scalene;
  }

  return flavor::unknown;
}

}  // namespace triangle
