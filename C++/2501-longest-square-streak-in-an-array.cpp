/////////////////////////////////////////////////////////////////////////////////////
// 2501 - Longest Square Streak in an Array
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/longest-square-streak-in-an-array/description/
// Solution: https://leetcode.com/problems/longest-square-streak-in-an-array/submissions/1436625164/
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::unordered_set<long long> numSet(nums.begin(), nums.end());
        int maxStreak = -1;
        
        for (int num : nums) {
            long long currentNum = num;
            int streakLength = 1;
            
            while (numSet.find(currentNum * currentNum) != numSet.end()) {
                currentNum *= currentNum;
                streakLength++;
            }
            
            if (streakLength >= 2) {
                maxStreak = std::max(maxStreak, streakLength);
            }
        }
        
        return maxStreak;
    }
};
