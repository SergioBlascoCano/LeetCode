/////////////////////////////////////////////////////////////////////////////////////
// 0001 - Two Sum
// Difficulty: EASY
// Exercise: https://leetcode.com/problems/two-sum/description/
// Solution: https://leetcode.com/problems/two-sum/submissions/1436590667
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (num_map.find(complement) != num_map.end()) {
                return std::vector<int>{num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return std::vector<int>();
    }
};
