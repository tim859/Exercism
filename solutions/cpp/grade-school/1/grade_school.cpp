#include "grade_school.h"
#include <algorithm>

namespace grade_school {

    void school::add(string name, int grade) {
        // check if the grade already exists and add the student name if so
        if (students.count(grade)) {
            students.at(grade).push_back(name);
            // sort the newly updated student name vector by alphabetical order
            sort(students.at(grade).begin(), students.at(grade).end());
        }
        // make a new grade (key) in the map and add the student name (value)
        else {
            students.emplace(grade, vector<string>{name});
        }
    }
}  // namespace grade_school
