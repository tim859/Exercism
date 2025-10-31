#include "pangram.h"
#include <bitset>
#include <algorithm>

namespace pangram {

    bool is_pangram(std::string sentence) {
        // normalise sentence to lowercase
        std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
        // use std::bitset to create a bitmask with 26 bits
        std::bitset<26> alphabetBits;
        
        for (size_t i = 0; i < sentence.length(); i++) {
            // only use the current character in the string if its a valid lowercase letter/ASCII character
            if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                // set the bit in the 26 bit long bitmask for the corresponding letter e.g. 'a' - 'a' returns 0 so we set the 0th bit to 1
                alphabetBits.set(sentence[i] - 'a');
            }
            if (alphabetBits.all()) 
                return true;                
        }
        return false;
    }

}  // namespace pangram
