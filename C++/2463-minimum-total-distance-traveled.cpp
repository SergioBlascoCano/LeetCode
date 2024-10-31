/////////////////////////////////////////////////////////////////////////////////////
// 2463 - Minimum Total Distance Traveled
// Difficulty: HARD
// Exercise: https://leetcode.com/problems/minimum-total-distance-traveled/description/
// Solution: https://leetcode.com/problems/minimum-total-distance-traveled/submissions/1438883931
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>
#include <limits.h>

class Solution {
public:
    long long minimumTotalDistance(std::vector<int>& robot, std::vector<std::vector<int>>& factory) {
        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(n + 1, LLONG_MAX));
        dp[0][0] = 0;

        for (int j = 1; j <= m; ++j) {
            dp[j][0] = 0;
            for (int i = 1; i <= n; ++i) {
                dp[j][i] = dp[j - 1][i];
                long long dist = 0;
                for (int k = 1; k <= factory[j - 1][1] && k <= i; ++k) {
                    dist += std::abs(factory[j - 1][0] - robot[i - k]);
                    if (dp[j - 1][i - k] != LLONG_MAX) {
                        dp[j][i] = std::min(dp[j][i], dp[j - 1][i - k] + dist);
                    }
                }
            }
        }

        return dp[m][n];
    }
};
