#if !defined(RNA_TRANSCRIPTION_H)
#define RNA_TRANSCRIPTION_H

#include <string>

namespace rna_transcription {
char to_rna(const char d);
std::string to_rna(const std::string dna_strand);
}  // namespace rna_transcription

#endif  // RNA_TRANSCRIPTION_H
