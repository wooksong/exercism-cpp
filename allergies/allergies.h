#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace allergies {
class allergy_test {
 public:
  static const uint32_t EGGS;
  static const uint32_t PEANUTS;
  static const uint32_t SHELLFISH;
  static const uint32_t STRAWBERRIES;
  static const uint32_t TOMATOES;
  static const uint32_t CHOCOLATE;
  static const uint32_t POLLEN;
  static const uint32_t CATS;

  allergy_test(uint32_t val = 0);
  bool is_allergic_to(std::string obj);
  std::unordered_set<std::string> get_allergies();

 private:
  const std::vector<uint32_t> m_codes = {
    allergy_test::EGGS,
    allergy_test::PEANUTS,
    allergy_test::SHELLFISH,
    allergy_test::STRAWBERRIES,
    allergy_test::TOMATOES,
    allergy_test::CHOCOLATE,
    allergy_test::POLLEN,
    allergy_test::CATS,
  };
  const std::unordered_map<uint32_t, std::string> m_dict = {
    {allergy_test::EGGS, "eggs"},
    {allergy_test::PEANUTS, "peanuts"},
    {allergy_test::SHELLFISH, "shellfish"},
    {allergy_test::STRAWBERRIES, "strawberries"},
    {allergy_test::TOMATOES, "tomatoes"},
    {allergy_test::CHOCOLATE, "chocolate"},
    {allergy_test::POLLEN, "pollen"},
    {allergy_test::CATS, "cats"},
  };

  uint32_t m_allergy_score;
};
}
#endif  // ALLERGIES_H
