/////////////////////////////////////////////////////////////////////////////////////
// 2684 - Maximum Number of Moves in a Grid
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/description/
// Solution: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/submissions/1437077405
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

class Solution {
public:
    int maxMoves(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int maxMoves = 0;
        
        for (int col = n - 2; col >= 0; --col) {
            for (int row = 0; row < m; ++row) {
                int moves = 0;
                if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
                    moves = std::max(moves, dp[row - 1][col + 1] + 1);
                }
                if (grid[row][col] < grid[row][col + 1]) {
                    moves = std::max(moves, dp[row][col + 1] + 1);
                }
                if (row < m - 1 && grid[row][col] < grid[row + 1][col + 1]) {
                    moves = std::max(moves, dp[row + 1][col + 1] + 1);
                }
                dp[row][col] = moves;
            }
        }
        
        for (int row = 0; row < m; ++row) {
            maxMoves = std::max(maxMoves, dp[row][0]);
        }
        
        return maxMoves;
    }
};
