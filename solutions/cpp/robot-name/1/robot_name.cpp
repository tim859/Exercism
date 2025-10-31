#include "robot_name.h"
#include <cstdlib>
#include <algorithm>

namespace robot_name {

    robot::robot() {
        robotName = generateNewName();
    }
    
    void robot::reset() {
        previousNames.emplace_back(robotName);
        std::string newName;
        bool newNameFound = false;
        while (!newNameFound) {
            newName = generateNewName();
            // if new name is not in list of previous names
            if (std::find(previousNames.begin(), previousNames.end(), newName) == previousNames.end()) {
                robotName = newName;
                newNameFound = true;
            }
        }
    }

    std::string robot::generateNewName() {
        std::string newName;
        newName += 'A' + rand() % 26;
        newName += 'A' + rand() % 26; 
        newName += '0' + rand() % 10; 
        newName += '0' + rand() % 10;
        newName += '0' + rand() % 10;
        return newName;
    }

}  // namespace robot_name
