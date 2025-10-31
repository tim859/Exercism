#include "protein_translation.h"

namespace protein_translation {

    std::map<std::string, std::string> codonProteinTable = {
    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"},
    {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
    {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}};

    std::vector<std::string> proteins(std::string rna) {
        std::vector<std::string> proteinList;
        // iterate through the rna string 3 characters at a time to get each codon
        for (size_t i = 0; i < rna.length(); i+=3) {
            // extract the codon from the rna string into a seperate substring
            std::string codon = rna.substr(i, 3);
            // check if the extracted codon matches a key in the map, if it does then store the value of that key in a new string
            if (codonProteinTable.count(codon)) {
                std::string protein = codonProteinTable[codon];
                // stop execution and return the proteinList if a STOP command is found
                if (protein == "STOP") {
                    return proteinList;
                }
                // if the protein value is not a STOP command then add it to the protein list
                proteinList.push_back(protein);
            }
        }        
        return proteinList;
    }

    

}  // namespace protein_translation
