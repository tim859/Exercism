#include "bob.h"
#include <cctype>

namespace bob {

    std::string hey(const std::string& string) {

        // loop iterates backwards to find the last non-whitespace character in the loop
        // if its '?' then the string is a question, if its any other character then the string isnt a question
        auto question{false};
        for (int i = string.length() - 1; i >= 0; i--) {
            if(std::isspace(static_cast<unsigned char>(string[i])))
                continue;
            if (string[i] == '?')
                question = true;
            break;
        }

        // loop iterates forwards marking if an uppercase/lowercase letter is found and also checking for non whitespace characters
        // only need to find one non whitespace character to know that the loop isnt whitespace
        auto lowerCaseFound{false};
        auto upperCaseFound{false};
        auto whitespace{true};
        for (auto character : string) {
            if (!upperCaseFound && character >= 'A' && character <= 'Z')
                upperCaseFound = true;
            if (!lowerCaseFound && character >= 'a' && character <= 'z')
                lowerCaseFound = true;
            if (whitespace && !std::isspace(static_cast<unsigned char>(character)))
                whitespace = false;
            // stop the loop when no more useful information can be gathered
            if (lowerCaseFound && upperCaseFound)
                break;
        }

        // if there are no lowercase characters but there is at least one uppercase character, then the string has to be all caps
        // otherwise it has to be lowercase
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
