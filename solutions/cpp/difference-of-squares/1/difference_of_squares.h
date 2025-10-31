#pragma once

namespace difference_of_squares {

    int square_of_sum(const int& num);
    int sum_of_squares(const int& num);
    inline int difference(const int& num) { return square_of_sum(num) - sum_of_squares(num); }

}  // namespace difference_of_squares
