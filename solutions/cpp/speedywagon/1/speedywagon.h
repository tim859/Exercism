#pragma once

#include <string>
#include <vector>

namespace speedywagon {
    
    struct pillar_men_sensor {
        int activity{};
        std::string location{};
        std::vector<int> data{};
    };    

    int uv_light_heuristic(std::vector<int>* data_array);
    inline bool connection_check(pillar_men_sensor* sensor) { return sensor != nullptr; }
    int activity_counter(pillar_men_sensor* sensor_array, int capacity);
    inline bool alarm_control(pillar_men_sensor* sensor) { return sensor != nullptr && sensor->activity > 0; }
    inline bool uv_alarm(pillar_men_sensor* sensor) { return sensor != nullptr && uv_light_heuristic(&sensor->data) > sensor->activity; }
}  // namespace speedywagon
