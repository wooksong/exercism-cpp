#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H

#include <map>
#include <vector>

namespace grade_school {
class school {
 public:
  std::map<int, std::vector<std::string>> roster() const;
  void add(const std::string &name, int grade);
  std::vector<std::string> grade(int grd) const;

 private:
  std::map<int, std::vector<std::string>> m_grade_to_names;
};

}  // namespace grade_school

#endif  // GRADE_SCHOOL_H
