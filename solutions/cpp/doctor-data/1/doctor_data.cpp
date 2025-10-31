#include "doctor_data.h"
heaven::Vessel::Vessel(std::string new_name, int new_generation) : name{new_name}, generation{new_generation}, current_system{star_map::System::Sol} {}

heaven::Vessel::Vessel(std::string new_name, int new_generation, star_map::System new_system) : name{new_name}, generation{new_generation}, current_system{new_system} {}

heaven::Vessel heaven::Vessel::replicate(std::string new_name) { return Vessel(new_name, generation + 1, current_system); }

void heaven::Vessel::make_buster() { busters++; }

bool heaven::Vessel::shoot_buster() { return busters--; }

std::string heaven::get_older_bob(Vessel vessel1, Vessel vessel2) {
    if (vessel1.generation < vessel2.generation)
        return vessel1.name;
    return vessel2.name;
}

bool heaven::in_the_same_system(Vessel vessel1, Vessel vessel2) { return vessel1.current_system == vessel2.current_system; }