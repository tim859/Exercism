#include "atbash_cipher.h"

namespace atbash_cipher {

    std::string encode(std::string plaintext) {
        std::string cipher;
        int spaceTracker = 0;
        for (size_t i = 0; i < plaintext.length(); i++) {
            // check if valid ascii character returned after plaintext character is passed through converter
            int ascii = getAtbashAscii(static_cast<int>(plaintext[i]));
            if (ascii != 0) {
                // add the character to the cipher
                cipher += static_cast<char>(ascii);
                // add whitespace after 5 characters have been added to the cipher
                spaceTracker++;
                if (spaceTracker % 5 == 0)
                    cipher += " ";
            }
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
            int ascii = getAtbashAscii(static_cast<int>(cipher[i]));
            if (ascii != 0)
                plaintext += static_cast<char>(ascii);
        }
        return plaintext;
    }

    int getAtbashAscii(int ascii) {
        // numbers 0 - 9
        if (ascii > 47 && ascii < 58)
                // return as is no change needed
                return ascii;
            
        // uppercase letters
        if (ascii > 64 && ascii < 91)
            // convert from uppercase to lowercase with ascii += 32
            // then covert to atbash with 219 - ascii (switches a to z and z to a e.t.c.)
            // 219 - (ascii + 32) == 187 - ascii
            return 187 - ascii;
            
        // lowercase letters
        if (ascii > 96 && ascii < 123)
            return 219 - ascii;

        // return 0 to signal a non valid ascii character that is not needed
        return 0;
    }

}  // namespace atbash_cipher
