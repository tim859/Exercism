#include "lasagna_master.h"

namespace lasagna_master {
    
    amount quantities(std::vector<std::string> layers) {
        int noodles = 0;
        double sauce = 0.0;
        for (size_t i = 0; i < layers.size(); i++) {
            if (layers[i] == "noodles")
                noodles += 50;
            if (layers[i] == "sauce")
                sauce += 0.2;
        }
        return amount{noodles, sauce};
    }

    std::vector<double> scaleRecipe(const std::vector<double>& quantities, double portions) {
        std::vector<double> newQuantities;
        for (size_t i = 0; i < quantities.size(); i++)
            newQuantities.emplace_back(quantities[i] * (portions / 2));
        return newQuantities;
    }
    
}  // namespace lasagna_master
