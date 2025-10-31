#pragma once
#include <string>
#include <vector>

namespace robot_name {

    class robot {
    private:
        std::string robotName;
        std::vector<std::string> previousNames;

    public:
        robot();
        inline std::string name() const { return robotName; }
        void reset();

    private:
        std::string generateNewName();
    };

}  // namespace robot_name
