#include "high_scores.h"

#include <algorithm>

namespace arcade {

std::vector<int> HighScores::list_scores() {
    // return all scores for this session
    return scores;
}

int HighScores::latest_score() {
    // return the latest score for this session
    return scores.back();
}

int HighScores::personal_best() {
    // return the highest score for this session.
    auto highScore{0};
    for (auto score : scores) {
        if (score > highScore)
            highScore = score;
    }
    return highScore;
}

std::vector<int> HighScores::top_three() {
    // return the top 3 scores for this session in descending order.
    std::vector<int> top3Scores{0};
    for (auto score : scores) {
        for (size_t i = 0; i < top3Scores.size(); ++i) {
            if (score > top3Scores[i]) {
                top3Scores.insert(top3Scores.begin() + i, score);
                break;
            }
        }
    }
    if (top3Scores.size() > 3)
        top3Scores.resize(3);
    if (top3Scores.back() == 0)
        top3Scores.pop_back();
    
    return top3Scores;
}

}  // namespace arcade
