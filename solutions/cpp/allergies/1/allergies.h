#pragma once

#include <string>
#include <unordered_set>
#include <bitset>
#include <vector>

namespace allergies {

    class allergy_test {
    private:
        const std::vector<std::string> allergens = {"eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"};
        const std::bitset<8> allergens_bits;
    
    public:
        allergy_test(const int& num) : allergens_bits(num) {}
        bool is_allergic_to(const std::string& test_allergen);
        std::unordered_set<std::string> get_allergies();
    };

}  // namespace allergies
