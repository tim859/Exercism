#pragma once
#include <string>
#include <array>

namespace kindergarten_garden {

    enum class Plants {
        grass,
        clover,
        radishes,
        violets
    };

    std::array<Plants, 4> plants(const std::string& shelves, const std::string& name);

}  // namespace kindergarten_garden
