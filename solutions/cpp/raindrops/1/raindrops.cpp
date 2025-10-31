#include "raindrops.h"

namespace raindrops {

    std::string convert(int num) {
        if ((num % 3 != 0) && (num % 5 != 0) && (num % 7 != 0))
            return std::to_string(num);
        std::string result = "";
        if (num % 3 == 0)
            result += "Pling";
        if (num % 5 == 0)
            result += "Plang";
        if (num % 7 == 0)
            result += "Plong";
        return result;
    }

}  // namespace raindrops
