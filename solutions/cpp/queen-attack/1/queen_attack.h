#pragma once

#include <string>
#include <utility>

namespace queen_attack {

    class chess_board {
    private:
        std::string board[8][8];
    
    public:
        chess_board(std::pair<int, int> white_queen, std::pair<int, int> black_queen);
        std::pair<int, int> get_piece_pos(const std::string& piece) const;
        inline std::pair<int, int> white() const { return get_piece_pos("wq"); }
        inline std::pair<int, int> black() const { return get_piece_pos("bq"); }
        bool can_attack() const;
    };

}  // namespace queen_attack
