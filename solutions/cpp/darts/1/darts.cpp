#include "darts.h"

namespace darts {

    int score(double x, double y) {
        // equation to tell if a point lies on a circle is x^2 + y^2 = r^2
        if ((x*x) + (y*y) > (100))
            return 0;
        if ((x*x) + (y*y) > (25))
            return 1;
        if ((x*x) + (y*y) > (1))
            return 5;
        return 10;
    }

}  // namespace darts
