#include "reverse_string.h"
#include <iostream>

namespace reverse_string {

    std::string reverse_string(std::string originalString) {

        std::list<char> stringList;
        std::string reversedString = "";

        for (long unsigned int i = 0; i < originalString.length(); i++) {
            stringList.push_front(originalString[i]);
        }
        
        for (long unsigned int i = 0; i < originalString.length(); i++) {
            reversedString += stringList.front();
            stringList.pop_front();
        }
        
        return reversedString;
    }

}  // namespace reverse_string
