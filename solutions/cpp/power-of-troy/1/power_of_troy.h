#pragma once

#include <string>
#include <memory>

namespace troy {

    struct artifact {
        // constructors needed (until C++20)
        artifact(std::string name) : name(name) {}
        std::string name;
    };
    
    struct power {
        // constructors needed (until C++20)
        power(std::string effect) : effect(effect) {}
        std::string effect;
    };    
    
    struct human {
        std::unique_ptr<artifact> possession;
        std::shared_ptr<power> own_power;
        std::shared_ptr<power> influenced_by;
    };

    inline void give_new_artifact(human& human, std::string artifact_name) { human.possession = std::make_unique<artifact>(artifact_name); }
    inline void exchange_artifacts(std::unique_ptr<artifact>& artifact1, std::unique_ptr<artifact>& artifact2) { std::swap(artifact1, artifact2); }
    inline void manifest_power(human& human, std::string power_name) { human.own_power = std::make_shared<power>(power_name); }
    inline void use_power(human& caster, human& target) { target.influenced_by = caster.own_power; }
    inline auto power_intensity(human& human) { return human.own_power.use_count(); }

}  // namespace troy
