#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {
    
    int steps(int num) {
        if (num < 1)
            throw std::domain_error("Input number is not valid");
        if (num == 1)
            return 0;

        int count = 0;
        while (num > 1) {
            (num % 2 == 0) ? even(num) : odd(num);
            ++count;
        }
        return count;
    }

}  // namespace collatz_conjecture
