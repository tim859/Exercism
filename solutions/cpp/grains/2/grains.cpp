#include "grains.h"
#include <climits>

namespace grains {

uint64_t square(int square) {
    return static_cast<uint64_t>(1) << (square - 1);
}

uint64_t total() {
    uint64_t total = 1;
    for (int i = 0; i < 64; i++) {
        // check whether the value of total has exceeded the maximum value that can be stored in a 64 bit unsigned integer and clamp it to its max value if it has
        if (square(i) > ULLONG_MAX - total) {
            total = ULLONG_MAX;
            break;
        }
        total += square(i);
    }
    return total;
}

}  // namespace grains
