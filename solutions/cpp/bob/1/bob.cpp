#include "bob.h"
#include <cctype>
#include <iostream>

namespace bob {

    std::string hey(const std::string& string) {
        auto lowerCaseFound{false};
        auto upperCaseFound{false};
        auto whitespace{true};
        auto question{false};

        for (int i = string.length() - 1; i >= 0; i--) {
            if(std::isspace(static_cast<unsigned char>(string[i])))
                continue;
            if (string[i] == '?')
                question = true;
            break;
        }
        
        for (auto character : string) {
            if (character >= 'A' && character <= 'Z')
                upperCaseFound = true;
            if (character >= 'a' && character <= 'z')
                lowerCaseFound = true;
            if (!std::isspace(static_cast<unsigned char>(character)))
                whitespace = false;
        }
        auto caps{false};
        if (upperCaseFound && !lowerCaseFound)
            caps = true;
        
        if (question && !caps)
            return "Sure.";
        if (!question && caps)
            return "Whoa, chill out!";
        if (question && caps)
            return "Calm down, I know what I'm doing!";
        if (whitespace)
            return "Fine. Be that way!";
        return "Whatever.";
    }

}  // namespace bob
