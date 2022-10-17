#include "protein_translation.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

namespace protein_translation {
std::vector<std::string> proteins(std::string rna_seq) {
  const std::unordered_map<std::string, std::string> dict = {
      {"AUG", "Methionine"}, {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
      {"UCU", "Serine"},     {"UCC", "Serine"},        {"UCA", "Serine"},
      {"UCG", "Serine"},     {"UUA", "Leucine"},       {"UUG", "Leucine"},
      {"UAU", "Tyrosine"},   {"UAC", "Tyrosine"},      {"UGU", "Cysteine"},
      {"UGC", "Cysteine"},   {"UGG", "Tryptophan"},
  };
  const std::vector<std::string> stop_codons = {
      "UAA",
      "UAG",
      "UGA",
  };
  const size_t len_codon = 3;
  std::string codon;
  std::vector<std::string> translated;
  size_t cnt = 0;

  for (size_t i = 0; i < rna_seq.length(); ++i) {
    cnt++;
    codon += rna_seq[i];

    if (cnt == len_codon) {
      cnt = 0;
      if (dict.find(codon) != dict.end()) {
        translated.push_back(dict.at(codon));
        codon.clear();
      } else if (std::find(stop_codons.begin(), stop_codons.end(), codon) !=
                 stop_codons.end()) {
        break;
      }
    }
  }

  return translated;
}
}  // namespace protein_translation
