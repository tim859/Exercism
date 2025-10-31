#pragma once

#include <vector>

namespace sieve {

    struct marked_num {
        int value;
        bool marked = false;
    };

    std::vector<int> primes(const int& given_num);

}  // namespace sieve
