#include "sieve.h"
#include <iostream>

namespace sieve {

    std::vector<int> primes(const int& given_num) {
        // write out all the numbers from 2 up to and including the given number
        std::vector<marked_num> marked_num_vector;
        for (auto i = 2; i <= given_num; i++) {
            marked_num_vector.emplace_back(marked_num{i});
        }

        std::vector<int> primes;
        // find the next unmarked number (skipping over marked numbers)
        for (auto& num : marked_num_vector) {
            if (!num.marked) {
                // mark all the multiples of that prime number as not prime
                for (auto i = num.value + num.value; i <= given_num; i += num.value)
                    marked_num_vector[i - 2].marked = true;      
                // add the marked_num value to a seperate vector<int> for returning the primes
                primes.emplace_back(num.value);
            }
        }
        return primes;
    }

}  // namespace sieve
