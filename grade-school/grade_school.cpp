#include "grade_school.h"

#include <algorithm>
#include <map>
#include <vector>

namespace grade_school {
std::map<int, std::vector<std::string>> school::roster() const {
  return this->m_grade_to_names;
}

void school::add(const std::string &name, int grade) {
  std::vector<std::string> *students;

  students = &(this->m_grade_to_names[grade]);
  students->push_back(name);
  std::sort(students->begin(), students->end());
}

std::vector<std::string> school::grade(int grd) const {
  if (this->m_grade_to_names.find(grd) == this->m_grade_to_names.end()) {
    return std::vector<std::string>();
  }
  return this->m_grade_to_names.at(grd);
}
}  // namespace grade_school
