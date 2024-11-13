/////////////////////////////////////////////////////////////////////////////////////
// 2563 - Count the Number of Fair Pairs
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
// Solution: https://leetcode.com/problems/count-the-number-of-fair-pairs/submissions/1451414300
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long count = 0;
        int n = nums.size();

        for (int i = 0; i < n - 1; ++i) {
            int left  = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin() - 1;

            if (left <= right) {
                count += right - left + 1;
            }
        }

        return count;
    }
};
