#include "sum_of_multiples.h"
#include <algorithm>
#include <numeric>

namespace sum_of_multiples {

    int to(const std::vector<int>& item_values, const int& player_level) {
        // validate function arguments
        if (item_values.empty() || player_level <= 0)
            return 0;
        
        // add all multiples to a vector
        std::vector<int> multiples;
        for (auto item_value : item_values) {
            for (auto i = item_value; i < player_level; i += item_value) {
                multiples.emplace_back(i);
            }
        }

        // remove all duplicate multiples
        std::sort(multiples.begin(), multiples.end());
        auto unique = std::unique(multiples.begin(), multiples.end());
        multiples.erase(unique, multiples.end());
        
        return std::accumulate(multiples.begin(), multiples.end(), 0);
    }

}  // namespace sum_of_multiples
