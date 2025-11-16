#include "isogram.h"
#include <cctype>

namespace isogram {

    bool is_isogram(std::string string) {

        // convert string to lowercase
        for (auto& character : string) {
            character = std::tolower(static_cast<unsigned char>(character));
        }

        // compare each character of the string to every other character in the string to find duplicates
        for (auto outerChar : string) {
            if (outerChar == ' ' || outerChar == '-')
                continue;
            auto count{0};
            for (auto innerChar : string) {
                if (innerChar == outerChar) {
                    ++count;
                    // count will always be at least 1 because it includes the character that is being checked
                    if (count > 1)
                        return false;
                }
            }
        }
        return true;
    }

}  // namespace isogram
