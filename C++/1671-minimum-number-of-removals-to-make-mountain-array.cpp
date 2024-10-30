/////////////////////////////////////////////////////////////////////////////////////
// 1671 - Minimum Number of Removals to Make Mountain Array
// Difficulty: HARD
// Exercise: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
// Solution: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/submissions/1438065410
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumMountainRemovals(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> lis(n, 1);
        std::vector<int> lds(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = std::max(lis[i], lis[j] + 1);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = std::max(lds[i], lds[j] + 1);
                }
            }
        }
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                maxMountainLength = std::max(maxMountainLength, lis[i] + lds[i] - 1);
            }
        }
        return n - maxMountainLength;
    }
};
