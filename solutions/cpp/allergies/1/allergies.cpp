#include "allergies.h"
#include <iostream>

namespace allergies {
    
    bool allergy_test::is_allergic_to(const std::string& test_allergen){
        for (size_t i = 0; i < allergens.size(); i++) {
            if (test_allergen == allergens[i])
                return allergens_bits[i];
        }
        return false;
    }
    
    std::unordered_set<std::string> allergy_test::get_allergies(){
        std::unordered_set<std::string> allergy_results;
        for (int i = 7; i >= 0; i--) {
            if (allergens_bits[i])
                allergy_results.emplace(allergens[i]);                
        }
        return allergy_results;
    }

}  // namespace allergies
