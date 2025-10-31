#include "speedywagon.h"

namespace speedywagon {
    
    int uv_light_heuristic(std::vector<int>* data_array) {
        double avg{};
        for (auto element : *data_array) {
            avg += element;
        }
        avg /= data_array->size();
        int uv_index{};
        for (auto element : *data_array) {
            if (element > avg) ++uv_index;
        }
        return uv_index;
    }

    int activity_counter(pillar_men_sensor* sensor_array, int capacity) {
        int activity = 0;
        for (int i = 0; i < capacity; i++) {
            activity += (sensor_array + i)->activity;
        }
        return activity;
    }
}  // namespace speedywagon
