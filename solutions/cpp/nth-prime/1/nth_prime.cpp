#include "nth_prime.h"
#include <cmath>
#include <stdexcept>

namespace nth_prime {

    int nth(const int& num) {
        if (num < 1)
            throw std::domain_error("Input cannot be less than 1");
        // my nth prime calculation doesn't work with 1 or 2 so these are returned manually
        switch (num) {
            case 1:
                return 2;
            case 2:
                return 3;
        }
        
        int count = 2;
        int last_prime;
        // iterates through every number until we have calculated enough primes
        for (int i = 2; count < num; i++) {
            // work out if that number is prime
            double sqrt_i = std::sqrt(static_cast<double>(i));
            for (int j = 2; j < sqrt_i; j++) {
                // if number is not prime, break to outer for loop without incrementing count
                if (i % j == 0)
                    break;
                // check to see if we have finished checking all numbers and are about to exit the loop
                if (j+1 > sqrt_i) {
                    last_prime = i;
                    ++count;
                }
            }            
        }
        return last_prime;
    }

}  // namespace nth_prime
