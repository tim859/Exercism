#pragma once
#include <string>
namespace star_map {
    enum class System {
        AlphaCentauri, 
        BetaHydri, 
        DeltaEridani, 
        EpsilonEridani, 
        Omicron2Eridani, 
        Sol
    };
}

namespace heaven {
    class Vessel {
    public:
        std::string name;
        int generation;
        star_map::System current_system;
        int busters;
        Vessel(std::string new_name, int new_generation);
        Vessel(std::string new_name, int new_generation, star_map::System new_system);
        Vessel replicate(std::string new_name);
        void make_buster();
        bool shoot_buster();
    };
    std::string get_older_bob(Vessel vessel1, Vessel vessel2);
    bool in_the_same_system(Vessel vessel1, Vessel vessel2);
}