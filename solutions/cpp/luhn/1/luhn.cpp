#include "luhn.h"

namespace luhn {

    bool valid(const std::string& string) {
        // reject any input that has one or no characters
        if (string.length() <= 1)
            return false;

        auto num = string;
        auto doubleThisDigit = false;
        auto sum = 0;
        for (int i = num.length() - 1; i >= 0; i--) {
            // remove whitespace from the string
            if (num[i] == ' ') {
                num.erase(i);
                continue;
            }
            // reject all other non-digit characters
            if (num[i] < '0' || num[i] > '9')
                return false;

            // double every alternate digit, subtracting 9 if the result is greater than 9
            // use bool flag doubleThisDigit to tell if we should be doubling this digit or not
            if (doubleThisDigit) {
                auto digit = (num[i] - '0') * 2;
                if (digit > 9)
                    digit -= 9;
                num[i] = char(digit + '0');
                doubleThisDigit = false;
            }
            else
                doubleThisDigit = true;

            // sum all the digits (doubled or not) as the loop iterates
            sum += num[i] - '0';
        } 

        // return invalid if the input is a single zero
        if (num.length() <= 1 && sum == 0)
            return false;
        
        return sum % 10 == 0;
    }

}  // namespace luhn
