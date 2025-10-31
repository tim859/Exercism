#include "hamming.h"
#include "stdexcept"

namespace hamming {

    int compute(std::string dna1, std::string dna2) {
        if (dna1.length() != dna2.length())
            throw std::domain_error("Strands cannot be different lengths");
        
        int differences = 0;
        for (size_t i = 0; i < dna1.length(); i++) {
            if (dna1[i] != dna2[i])
                differences++;
        }
        return differences;
    }

}  // namespace hamming
