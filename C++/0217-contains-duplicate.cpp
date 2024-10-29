/////////////////////////////////////////////////////////////////////////////////////
// 0217 - Contains Duplicate
// Difficulty: EASY
// Exercise: https://leetcode.com/problems/contains-duplicate/description/
// Solution: https://leetcode.com/problems/contains-duplicate/submissions/1437285910
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
