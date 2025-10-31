#pragma once
#include <string>

namespace date_independent {

    class clock {
    private:
        int hour;
        int minute;
    
    public:
        clock(int newHour, int newMinute);
        static clock at(int hour, int minute);
        clock plus(int addMinutes) const;
        operator std::string() const;   
        bool operator==(const clock& other) const;
        bool operator!=(const clock& other) const;
    };

}  // namespace date_independent
