#include "hexadecimal.h"
#include <algorithm>

namespace hexadecimal {

    int convert(const std::string& string) {
        // reverse the hex characters for easier calculation using the iterator in the loop
        auto hex = string;
        std::reverse(hex.begin(), hex.end());
        
        auto currentValue = 0;
        auto decimal = 0;
        auto power = 1;
        for (size_t i = 0; i < hex.length(); i++) {
            // reject all strings with a non hex character
            if (hex[i] < '0' || (hex[i] > '9' && hex[i] < 'a') || hex[i] > 'f')
                return 0;

            // set currentValue to the respective decimal number if hex digit is a to f
            if (hex[i] >= 'a')
                currentValue = 10 + (hex[i] - 'a');
            // otherwise hex digit has to be 0 to 9 and currentValue can just be set to that value
            else
                currentValue = hex[i] - '0';

            // multiply each digit by its power of 16 and sum them as the loop iterates
            decimal += currentValue * power;
            power *= 16;
        }        
        return decimal;
    }

}  // namespace hexadecimal
