#include "isbn_verifier.h"

namespace isbn_verifier {

    bool is_valid(std::string isbn) {
        // sISBN = sanitised isbn
        std::string sISBN = "";
        // accept numbers and X, ignore dashes and reject the isbn if it includes any other input characters
        for (size_t i = 0; i < isbn.length(); i++) {
            if ((isbn[i] >= '0' && isbn[i] <= '9') || isbn[i] == 'X')
                sISBN += isbn[i];
            else if (isbn[i] == '-')
                continue;
            else
                return false;
        }
        // make sure the sanitised isbn has exactly 10 characters
        if (sISBN.length() != 10)
            return false;

        // if the last character is still 'X' in the isbn that needs to be turned into the integer 10
        // ascii characters 0 - 9 can be converted to integers by subtracting ascii zero
        auto x = (sISBN[9] == 'X') ? 10 : sISBN[9] - '0';

        // return bool result of isbn formula (d₁ * 10 + d₂ * 9 + d₃ * 8 + d₄ * 7 + d₅ * 6 + d₆ * 5 + d₇ * 4 + d₈ * 3 + d₉ * 2 + d₁₀ * 1) mod 11
        auto sum = 0;
        for (auto i = 0; i < 9; i++) {
            sum += (sISBN[i] - '0') * (10 - i);
        }
        return (sum + x) % 11 == 0;       
    }

}  // namespace isbn_verifier
