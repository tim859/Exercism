#pragma once

namespace space_age {
    class space_age {
    private:
        long int ageInSeconds;
        const double earthYearInSeconds = 31557600;
        const double mercuryOrbitalPeriod = 0.2408467;
        const double venusOrbitalPeriod = 0.61519726;
        const double marsOrbitalPeriod = 1.8808158;
        const double jupiterOrbitalPeriod = 11.862615;
        const double saturnOrbitalPeriod = 29.447498;
        const double uranusOrbitalPeriod = 84.016846;
        const double neptuneOrbitalPeriod = 164.79132;
    public:
        space_age(long int age); // constructor
        long int seconds() const;
        double on_earth() const;
        double on_mercury() const;
        double on_venus() const;
        double on_mars() const;
        double on_jupiter() const;
        double on_saturn() const;
        double on_uranus() const;
        double on_neptune() const;  
    };
}  // namespace space_age
