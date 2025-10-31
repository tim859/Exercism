#include "rna_transcription.h"

namespace rna_transcription {

    char to_rna(char dna) {
        switch (dna) {
            case 'G':
                return 'C';
            case 'C':
                return 'G';
            case 'T':
                return 'A';
            default:
                return 'U';  
        }
    }
    
    std::string to_rna(std::string dna) {
        std::string rna = "";
        for (size_t i = 0; i < dna.length(); i++) {
            switch (dna[i]) {
                case 'G':
                    rna += 'C';
                    break;
                case 'C':
                    rna += 'G';
                    break;
                case 'T':
                    rna += 'A';
                    break;
                case 'A':
                    rna += 'U';
                    break;                      
            }
        }
        return rna;
    }

}  // namespace rna_transcription
