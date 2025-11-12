#include "matching_brackets.h"
#include <stack>

namespace matching_brackets {

    bool check(const std::string& string) {
        std::stack<char> brackets;
        for (auto c : string) {            
            switch (c) {
                case '[':
                    brackets.push(']');
                    break;
                case '{':
                    brackets.push('}');
                    break;
                case '(':
                    brackets.push(')');
                    break;
            }
            
            if (c == ']' || c == '}' || c == ')') {
                if (brackets.empty() || brackets.top() != c)
                    return false;
                brackets.pop();
            }
        }
        return brackets.empty();
    }
}  // namespace matching_brackets
