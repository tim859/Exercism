#include "pig_latin.h"
#include <algorithm>
#include <regex>

namespace pig_latin {
    const std::string rule1(const std::string& word) {
        // static so the regex is compiled just once
        static const std::regex rule1(R"(^(?:[aeiou]|xr|yt).*)");   
        return std::regex_match(word, rule1) ? word + "ay" : word;
    }
    
    const std::string rule2(const std::string& word) {
        static const std::regex rule2(R"(^([^aeiou]+)(.*)$)");   
        return std::regex_match(word, rule2) ? std::regex_replace(word, rule2, std::string{"$2$1ay"}) : word;
    }
    
    const std::string rule3(const std::string& word) {
        static const std::regex rule3(R"(^([^aeiou]*qu)(.*)$)");
        return std::regex_match(word, rule3) ? std::regex_replace(word, rule3, std::string{"$2$1ay"}) : word;
    }
    
    const std::string rule4(const std::string& word) {
        static const std::regex rule4(R"(^([^aeiou]+)(y.*)$)");
        return std::regex_match(word, rule4) ? std::regex_replace(word, rule4, std::string{"$2$1ay"}) : word;
    }

    const std::string translate(const std::string& english) {
        std::string result;
        std::string word;
        for (size_t i = 0; i < english.length(); i++) {
            word += english[i];
            // check if we have reached the end of the word or the end of the sentence
            if (english[i+1] == ' ' || i+1 == english.length()) {
                // apply a rule and check whether it changed the word, if it didn't then we go to the next rule, if it did then we move on
                std::string translatedWord = rule1(word);
                if (translatedWord == word) {
                    translatedWord = rule3(word);
                    if (translatedWord == word) {
                        translatedWord = rule4(word);
                        if (translatedWord == word) {
                            // rule 2 needs to go last as it would incorrectly apply to words that should have rules 2 or 3 applied instead
                            translatedWord = rule2(word);
                        }
                    }
                }
                word.erase();
                result += translatedWord;
                // adds spaces in between words by checking that we haven't yet reached the end of the sentence
                if (i+1 < english.length()) {
                    result += " ";
                    i++;
                }
            }
        }
        return result;
    }

}  // namespace pig_latin
