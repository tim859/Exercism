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
            
            switch (hex[i]) {
                case 'a':
                    currentValue = 10;
                    break;
                case 'b':
                    currentValue = 11;
                    break;
                case 'c':
                    currentValue = 12;
                    break;
                case 'd':
                    currentValue = 13;
                    break;
                case 'e':
                    currentValue = 14;
                    break;
                case 'f':
                    currentValue = 15;
                    break;
                default:
                    currentValue = hex[i] - '0';
            }
            decimal += currentValue * power;
            power *= 16;
        }        
        return decimal;
    }

}  // namespace hexadecimal
