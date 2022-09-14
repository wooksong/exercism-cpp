#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

#include <stdint.h>

namespace space_age {
constexpr double earth_year_in_secs = 31557600;
constexpr double mercury_year_in_earth_year = 0.2408467;
constexpr double venus_year_in_earth_year = 0.61519726;
constexpr double mars_year_in_earth_year = 1.8808158;
constexpr double jupiter_year_in_earth_year = 11.862615;
constexpr double saturn_year_in_earth_year = 29.447498;
constexpr double uranus_year_in_earth_year = 84.016846;
constexpr double neptune_year_in_earth_year = 164.79132;

class space_age {
 private:
  uint64_t m_seconds;
  space_age();

 public:
  explicit space_age(uint64_t sec);
  uint64_t seconds() const;
  double on_mercury() const;
  double on_venus() const;
  double on_earth() const;
  double on_mars() const;
  double on_jupiter() const;
  double on_saturn() const;
  double on_uranus() const;
  double on_neptune() const;
};
}  // namespace space_age

#endif  // SPACE_AGE_H
