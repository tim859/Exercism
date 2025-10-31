#include "difference_of_squares.h"

namespace difference_of_squares {

    int square_of_sum(const int& num) {
        int result = 0;
        for (int i = 1; i <= num; i++)
            result += i;
        return result * result;
    }
    
    int sum_of_squares(const int& num) {
        int result = 0;
        for (int i = 1; i <= num; i++)
            result += (i*i);
        return result;
    }
}  // namespace difference_of_squares
