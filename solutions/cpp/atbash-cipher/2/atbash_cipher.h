#pragma once
#include <string>

namespace atbash_cipher {

    std::string encode(std::string plaintext);
    std::string decode(std::string cipher);
    int getAtbashAscii(int ascii);

}  // namespace atbash_cipher
