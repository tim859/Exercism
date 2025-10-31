#include "triangle.h"
#include "stdexcept"

namespace triangle {
    flavor kind(double a, double b, double c) {        
        if (a <= 0 || b <= 0 || c <= 0)
            throw std::domain_error("Triangle is not valid: At least one side is less than or equal to 0");
        if ((a + b < c) || (b + c < a) || (a + c < b))
            throw std::domain_error("Triangle is not valid: The sum of the lengths of two side are less than the length of the third side");
        if (a == b && b == c)
            return flavor::equilateral;
        if ((a == b && b != c) || (b == c && c != a) || (c == a && a != b))
            return flavor::isosceles;
        return flavor::scalene;
    }
}  // namespace triangle
