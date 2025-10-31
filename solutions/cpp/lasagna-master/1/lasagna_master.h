#pragma once
#include <vector>
#include <string>

namespace lasagna_master {

    struct amount {
        int noodles;
        double sauce;
    };
    
    inline int preparationTime(std::vector<std::string> layers) { return layers.size() * 2; }
    inline int preparationTime(std::vector<std::string> layers, int avg_prep_time) { return layers.size() * avg_prep_time; }
    inline void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string> friendsList) { myList.back() = friendsList.back(); }
    inline void addSecretIngredient(std::vector<std::string>& myList, const std::string friendsList) { myList.back() = friendsList; }
    amount quantities(std::vector<std::string> layers);
    std::vector<double> scaleRecipe(const std::vector<double>& quantities, double portions);

}  // namespace lasagna_master
