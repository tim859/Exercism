#include "clock.h"
#include <sstream>
#include <iomanip>

namespace date_independent {

    clock::clock(int newHour, int newMinute) {
        int totalMinutes = newHour * 60 + newMinute;
        totalMinutes = ((totalMinutes % 1440) + 1440) % 1440;
        hour = totalMinutes / 60;
        minute = totalMinutes % 60;
    }
    
    clock clock::at(int hour, int minute) {
        return clock(hour, minute);
    }
    
    clock clock::plus(int addMinutes) const {
        return clock(hour, minute + addMinutes);
    }

    clock::operator std::string() const {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hour << ":" << std::setw(2) << std::setfill('0') << minute;
        return oss.str();
    }

    bool clock::operator==(const clock& other) const {
        return hour == other.hour && minute == other.minute;
    }

    bool clock::operator!=(const clock& other) const {
        return hour != other.hour || minute != other.minute;
    }

}  // namespace date_independent
