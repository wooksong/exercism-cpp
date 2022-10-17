#if !defined(PROTEIN_TRANSLATION_H)
#define PROTEIN_TRANSLATION_H

#include <string>
#include <vector>

namespace protein_translation {
std::vector<std::string> proteins(std::string rna_seq);
}  // namespace protein_translation

#endif  // PROTEIN_TRANSLATION_H
