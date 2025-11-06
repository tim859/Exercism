#include "acronym.h"
#include <cctype>

namespace acronym {

    std::string acronym(std::string sentence) {
        std::string acronym;
        auto newWord = true;
        for (auto c : sentence) {
            // add the character to the acronym if its the first letter of a new word
            if (newWord && ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
                acronym += std::toupper(c);
                newWord = false;
            }
            if (c == ' ' || c == '-')
                newWord = true;
        }
        return acronym;
    }

}  // namespace acronym
