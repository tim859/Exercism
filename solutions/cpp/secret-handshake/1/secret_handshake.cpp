#include "secret_handshake.h"
#include <bitset>
#include <algorithm>

namespace secret_handshake {
    
    std::vector<std::string> commands(const int& num) {
        std::bitset<5> bits(num);
        std::vector<std::string> actions;
        if (bits[0])
            actions.emplace_back("wink");
        if (bits[1])
            actions.emplace_back("double blink");
        if (bits[2])
            actions.emplace_back("close your eyes");
        if (bits[3])
            actions.emplace_back("jump");
        if (bits[4])
            std::reverse(actions.begin(), actions.end());
        return actions;
    }
    
}  // namespace secret_handshake
