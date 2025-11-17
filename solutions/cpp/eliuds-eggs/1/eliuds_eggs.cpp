#include "eliuds_eggs.h"

namespace chicken_coop {

    int positions_to_quantity(int decimal) {
        auto eggCount{0};
        while (decimal > 0) {
            if ((decimal % 2) == 1)
                eggCount++;
            decimal /= 2;
        }
        return eggCount;
    }

}  // namespace chicken_coop