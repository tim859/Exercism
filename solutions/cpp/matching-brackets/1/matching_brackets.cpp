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
                case ']':
                    if (brackets.empty() || brackets.top() != ']')
                        return false;
                    brackets.pop();
                    break;
                case '}':
                    if (brackets.empty() || brackets.top() != '}')
                        return false;
                    brackets.pop();
                    break;
                case ')':
                    if (brackets.empty() || brackets.top() != ')')
                        return false;
                    brackets.pop();
                    break;
            }
        }
        return brackets.empty();
    }

}  // namespace matching_brackets
