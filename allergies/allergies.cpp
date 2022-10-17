#include "allergies.h"

#include <unordered_map>

namespace allergies {
const uint32_t allergy_test::EGGS = 1U;
const uint32_t allergy_test::PEANUTS = EGGS << 1;
const uint32_t allergy_test::SHELLFISH = EGGS << 2;
const uint32_t allergy_test::STRAWBERRIES = EGGS << 3;
const uint32_t allergy_test::TOMATOES = EGGS << 4;
const uint32_t allergy_test::CHOCOLATE = EGGS << 5;
const uint32_t allergy_test::POLLEN = EGGS << 6;
const uint32_t allergy_test::CATS = EGGS << 7;

allergy_test::allergy_test(uint32_t val) { this->m_allergy_score = val; }

bool allergy_test::is_allergic_to(const std::string obj) {
  for (auto iter = this->m_codes.begin(); iter != this->m_codes.end(); ++iter) {
    if (((*iter) & this->m_allergy_score) && (this->m_dict.at(*iter) == obj)) {
      return true;
    }
  }
  return false;
}

std::unordered_set<std::string> allergy_test::get_allergies() {
  std::unordered_set<std::string> ret;

  for (auto iter = this->m_codes.begin(); iter != this->m_codes.end(); ++iter) {
    if ((*iter) & this->m_allergy_score) {
      ret.insert(this->m_dict.at(*iter));
    }
  }
  return ret;
}
}  // namespace allergies
