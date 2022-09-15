#if !defined(TRIANGLE_H)
#define TRIANGLE_H

namespace triangle {
enum flavor {
  unknown,
  equilateral,
  isosceles,
  scalene,
};

flavor kind(double side_one, double side_two, double side_three);
}  // namespace triangle

#endif  // TRIANGLE_H
