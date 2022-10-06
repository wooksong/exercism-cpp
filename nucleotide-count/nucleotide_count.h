#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H

#include <map>
#include <string>

namespace nucleotide_count {

class counter {
 public:
  counter(const std::string dna_sq);
  std::map<char, int> nucleotide_counts() const;
  int count(char n) const;

 private:
  counter();

  std::map<char, int> m_nucleotide_to_counts;
};

}  // namespace nucleotide_count

#endif  // NUCLEOTIDE_COUNT_H
