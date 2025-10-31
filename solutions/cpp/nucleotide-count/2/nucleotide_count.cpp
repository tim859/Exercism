#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

    std::map<char, int> count(std::string dnaSequence) {
        std::map<char, int> dnaCount{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};
        for (size_t i = 0; i < dnaSequence.length(); i++) {
            switch (dnaSequence[i]) {
                case 'A':
                    dnaCount.emplace('A', dnaCount.at('A')++);
                    break;
                case 'C':
                    dnaCount.emplace('C', dnaCount.at('C')++);
                    break;
                case 'G': 
                    dnaCount.emplace('G', dnaCount.at('G')++);
                    break;
                case 'T': 
                    dnaCount.emplace('T', dnaCount.at('T')++);
                    break;
                default:
                    throw std::invalid_argument("Invalid character in DNA sequence");
            }
        }
        return dnaCount;
    }

}  // namespace nucleotide_count
