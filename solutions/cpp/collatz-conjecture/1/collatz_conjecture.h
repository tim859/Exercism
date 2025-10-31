#pragma once

namespace collatz_conjecture {

    constexpr inline void even(int& num) { num /= 2; }
    constexpr inline void odd(int& num) { (num *= 3) += 1; }
    int steps(int num);

}  // namespace collatz_conjecture
