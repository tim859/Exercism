#include "leap.h"

namespace leap {
    bool is_leap_year(int year) {
        if (year % 4 == 0) {
	        if (year % 100 == 0) {
		        if (year % 400 == 0) {
			        // divisible by 4, divisible by 100, divisible by 400
			        return true;
		        }
		        // divisible by 4, divisible by 100, not divisible by 400
		        return false;
	        }
	        // divisible by 4, not divisible by 100
	        return true;
        }
        // not divisible by 4
        return false;
    }
}  // namespace leap
