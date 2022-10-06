#include "rna_transcription.h"

#include <map>
#include <string>

namespace rna_transcription {
static std::map<char, char> dna_to_rna = {
    {'G', 'C'}, {'C', 'G'}, {'T', 'A'}, {'A', 'U'}};

char to_rna(const char d) { return dna_to_rna[d]; }

std::string to_rna(const std::string dna_strand) {
  std::string r;

  for (char d : dna_strand) {
    r.append(std::string(1, dna_to_rna[d]));
  }

  return r;
}
}  // namespace rna_transcription
