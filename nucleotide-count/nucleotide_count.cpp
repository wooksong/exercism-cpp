#include "nucleotide_count.h"

#include <stdexcept>
#include <string>

namespace nucleotide_count {

constexpr char NUCLEOTIDES[] = {'A', 'C', 'G', 'T'};
constexpr char ERRMSG_EINVAL[] =
    " is not the character representing one of the nucleotides";

counter::counter(const std::string dna_sq) {
  std::string nucleotides(NUCLEOTIDES);

  for (size_t n = 0; n < sizeof(NUCLEOTIDES); ++n) {
    this->m_nucleotide_to_counts[NUCLEOTIDES[n]] = 0;
  }

  for (auto n : dna_sq) {
    if (nucleotides.find(n) == std::string::npos) {
      throw std::invalid_argument(std::string(1, n).append(ERRMSG_EINVAL));
    }

    this->m_nucleotide_to_counts[n]++;
  }
}

std::map<char, int> counter::nucleotide_counts() const {
  return this->m_nucleotide_to_counts;
}

int counter::count(char n) const {
  if (std::string(NUCLEOTIDES).find(n) == std::string::npos) {
    throw std::invalid_argument(std::string(1, n).append(ERRMSG_EINVAL));
  }
  return this->m_nucleotide_to_counts.at(n);
}

}  // namespace nucleotide_count
