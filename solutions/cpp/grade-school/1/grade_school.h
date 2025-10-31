#pragma once

#include <string>
#include <vector>
#include <map>

namespace grade_school {

    // usually avoid but the constant std:: is making it more difficult to read in this case
    using namespace std;
    
    class school {
    private:
        map<int, vector<string>> students{};
        
    public:
        void add(string name, int grade);
        inline map<int, vector<string>> roster() const { return students; }
        inline vector<string> grade(int grade) const { return students.count(grade) ? students.at(grade) : vector<string>{}; }
    };

}  // namespace grade_school
