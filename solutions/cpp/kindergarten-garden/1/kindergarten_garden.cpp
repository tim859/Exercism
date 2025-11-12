#include "kindergarten_garden.h"
#include <cctype>

namespace kindergarten_garden {

    std::array<Plants, 4> plants(const std::string& shelves, const std::string& name) {

        std::array<std::string, 12> students = {"Alice", "Bob", "Charlie", "David", "Eve", "Fred", 
        "Ginny", "Harriet", "Ileana", "Joseph", "Kincaid", "Larry"};
        
        // find student index and calculate plant index
        auto plantIndex{0};
        for (size_t i = 0; i < students.size(); ++i) {
            if (students[i] == name)
                // gives the index of the students first plant on each shelf
                plantIndex = ((i + 1) * 2) - 2;
        }

        // split the shelves string into two individual substrings for easier manipulation
        // use the newline character in the middle to know where to split
        std::string firstShelf;
        std::string secondShelf;
        for (size_t i = 0; i < shelves.length(); ++i) {
            if (std::isspace(static_cast<unsigned char>(shelves[i]))) {
                firstShelf = shelves.substr(0, i);
                secondShelf = shelves.substr(i+1);
                break;
            }
        }
        std::string plantCodes = firstShelf.substr(plantIndex, 2) + secondShelf.substr(plantIndex, 2);
        
        std::array<Plants, 4> plants;
        for (size_t i = 0; i < plants.size(); ++i) {
            switch (plantCodes[i]) {
                case 'G':
                    plants[i] = Plants::grass;
                    break;
                case 'C':
                    plants[i] = Plants::clover;
                    break;
                case 'R':
                    plants[i] = Plants::radishes;
                    break;
                case 'V':
                    plants[i] = Plants::violets;
                    break;
            }
        }
        return plants;
    }

}  // namespace kindergarten_garden
