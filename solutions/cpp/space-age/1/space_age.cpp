#include "space_age.h"
#include <iostream>

namespace space_age {
    
    space_age::space_age(long int age) {
        ageInSeconds = age;
    }
        
    long int space_age::seconds() const {
        return ageInSeconds;
    }

    double space_age::on_earth() const {
        return ageInSeconds / earthYearInSeconds;
    }
        
    double space_age::on_mercury() const {
        return on_earth() / mercuryOrbitalPeriod;
    }
        
    double space_age::on_venus() const {
        return on_earth() / venusOrbitalPeriod;
    }
            
    double space_age::on_mars() const {
        return on_earth() / marsOrbitalPeriod;
    }
            
    double space_age::on_jupiter() const {
        return on_earth() / jupiterOrbitalPeriod;
    }
            
    double space_age::on_saturn() const {
        return on_earth() / saturnOrbitalPeriod;
    }
            
    double space_age::on_uranus() const {
        return on_earth() / uranusOrbitalPeriod;
    }
            
    double space_age::on_neptune() const {
        return on_earth() / neptuneOrbitalPeriod;
    }   
}  // namespace space_age
