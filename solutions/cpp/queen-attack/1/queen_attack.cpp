#include "queen_attack.h"
#include <stdexcept>

namespace queen_attack {

    chess_board::chess_board(std::pair<int, int> white_queen, std::pair<int, int> black_queen) {
        if (white_queen.first < 0 || white_queen.first > 7 || white_queen.second < 0 || white_queen.second > 7 || 
            black_queen.first < 0 || black_queen.first > 7 || black_queen.second < 0 || black_queen.second > 7 || 
            white_queen == black_queen)
            throw std::domain_error("Queens must have valid board positions");
            
        board[white_queen.first][white_queen.second] = "wq";
        board[black_queen.first][black_queen.second] = "bq";
    }

    std::pair<int, int> chess_board::get_piece_pos(const std::string& piece) const {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == piece)
                    return std::make_pair(i, j);
            }
        }
        throw std::domain_error("Piece is not valid");
    }
    
    bool chess_board::can_attack() const {
        auto white_queen = get_piece_pos("wq");

        // check for horizontal/vertical collisions
        for (auto i = 0; i < 8; i++) {
            if (board[white_queen.first][i] == "bq" || board[i][white_queen.second] == "bq")
                return true;
        }

        // check for diagonal collisions
        for (auto i = 1; i < 8; i++) {
            // south east collisions
            if (white_queen.first + i < 8 && white_queen.second + i < 8) {
                if (board[white_queen.first + i][white_queen.second + i] == "bq")
                    return true;
            }       
            // south west collisions
            if (white_queen.first - i >= 0 && white_queen.second + i < 8) {
                if (board[white_queen.first - i][white_queen.second + i] == "bq")
                    return true;
            }  
            // north west collisions
            if (white_queen.first - i >= 0 && white_queen.second - i >= 0) {
                if (board[white_queen.first - i][white_queen.second - i] == "bq")
                    return true;
            }  
            // north east collisions
            if (white_queen.first + i < 8 && white_queen.second - i >= 0) {
                if (board[white_queen.first + i][white_queen.second - i] == "bq")
                    return true;
            }  
        }
        return false;
    }

}  // namespace queen_attack
