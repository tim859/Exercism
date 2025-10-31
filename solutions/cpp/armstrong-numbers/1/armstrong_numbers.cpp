#include "armstrong_numbers.h"
#include <string>
#include <cmath>

namespace armstrong_numbers {

    bool is_armstrong_number(int num) {
        std::string numString = std::to_string(std::abs(num));
        int armstrongCheck = 0;
        for (size_t i = 0; i < numString.length(); i++) {
            // convert char to int
            int digit = numString[i] - '0';
            armstrongCheck += std::pow(digit, numString.length());
        }
        return armstrongCheck == num;
    }

}  // namespace armstrong_numbers
