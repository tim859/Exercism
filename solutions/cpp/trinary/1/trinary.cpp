#include "trinary.h"
#include <algorithm>

namespace trinary {

    int to_decimal(const std::string& string) {
        auto trinary = string;
        std::reverse(trinary.begin(), trinary.end());
        
        auto decimal{0};
        auto power{1};
        for (auto digit : trinary) {
            // reject all strings with a non trinary character
            if (digit < '0' || digit > '2')
                return false;

            // multiply each digit by its place in the string to the power of 3 and sum the results as the loop iterates
            decimal += (digit - '0') * power;
            power *= 3;
        }
        return decimal;
    }

}  // namespace trinary
