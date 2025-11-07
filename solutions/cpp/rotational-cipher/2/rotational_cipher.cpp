#include "rotational_cipher.h"
#include <cctype>

namespace rotational_cipher {

    std::string rotate(const std::string& text, int key) {
        std::string cipher;
        for (auto& character : text) {
            if (std::isalpha(character)) {
                auto aCase = std::isupper(character) ? 'A' : 'a';
                // convert from ascii to 0 - 25 range by subtracting 'A' or 'a', shift by key amount, wrap around within alphabet, cast back to ascii
                cipher += char((character - aCase + key) % 26 + aCase);
            }
            else
                cipher += character;
        }
        return cipher;
    }

}  // namespace rotational_cipher
