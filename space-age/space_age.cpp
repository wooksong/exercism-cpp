#include "space_age.h"

#include <stdint.h>

#include <iostream>

namespace space_age {
space_age::space_age(uint64_t sec) : m_seconds(sec) {}

uint64_t space_age::seconds() const { return this->m_seconds; }

double space_age::on_mercury() const {
  return this->m_seconds / earth_year_in_secs / mercury_year_in_earth_year;
}

double space_age::on_venus() const {
  return this->m_seconds / earth_year_in_secs / venus_year_in_earth_year;
}

double space_age::on_earth() const {
  return this->m_seconds / earth_year_in_secs;
}

double space_age::on_mars() const {
  return this->m_seconds / earth_year_in_secs / mars_year_in_earth_year;
}

double space_age::on_jupiter() const {
  return this->m_seconds / earth_year_in_secs / jupiter_year_in_earth_year;
}

double space_age::on_saturn() const {
  return this->m_seconds / earth_year_in_secs / saturn_year_in_earth_year;
}

double space_age::on_uranus() const {
  return this->m_seconds / earth_year_in_secs / uranus_year_in_earth_year;
}

double space_age::on_neptune() const {
  return this->m_seconds / earth_year_in_secs / neptune_year_in_earth_year;
}
}  // namespace space_age
