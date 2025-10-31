#include "atbash_cipher.h"

namespace atbash_cipher {

    std::string encode(std::string plaintext) {
        std::string cipher;
        int spaceTracker = 0;
        for (size_t i = 0; i < plaintext.length(); i++) {
            // get the ascii code of the current character
            int ascii = static_cast<int>(plaintext[i]);
            // if character is a number 0 - 9
            if (ascii > 47 && ascii < 58)
                // append directly to cipher as no processing needed
                cipher += plaintext[i];
            // if character is an uppercase letter
            else if (ascii > 64 && ascii < 91) {
                // convert from uppercase to lowercase
                ascii += 32;
                // covert to atbash by subtracting from 219, then cast back from ascii int to char and append to cipher
                cipher += static_cast<char>(219 - ascii);
            }
            // if character is lowercase then do same as before without case conversion
            else if (ascii > 96 && ascii < 123)
                cipher += static_cast<char>(219 - ascii);
            else
                // any other ascii value can be ignored
                continue;

            // add whitespace after 5 characters have been added to the cipher
            spaceTracker++;
            if (spaceTracker % 5 == 0)
                cipher += " ";
        }      
        // fix the edge case where 5 valid ascii chars are followed by an arbitrary number of non valid ascii chars 
        // right before the plaintext string ends leading to an incorrect space at the end of the cipher
        if (cipher[cipher.length() - 1] == ' ')
            cipher.pop_back();
        return cipher;
    }
    
    std::string decode(std::string cipher) {
        std::string plaintext;
        for (size_t i = 0; i < cipher.length(); i++) {
            int ascii = static_cast<int>(cipher[i]);
            // numbers 0 - 9
            if (ascii > 47 && ascii < 58)
                plaintext += cipher[i];
            // lowercase letters
            if (ascii > 96 && ascii < 123)
                plaintext += static_cast<char>(219 - ascii);
        }
        return plaintext;
    }

}  // namespace atbash_cipher
