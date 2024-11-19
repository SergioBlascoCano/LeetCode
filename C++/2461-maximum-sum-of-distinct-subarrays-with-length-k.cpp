/////////////////////////////////////////////////////////////////////////////////////
// 2461 - Maximum Sum of Distinct Subarrays With Length K
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/
// Solution: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/submissions/1457035240
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <unordered_map>

class Solution {
public:
    long long maximumSubarraySum(std::vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, currentSum = 0;
        std::unordered_map<int, int> freq;

        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            freq[nums[i]]++;

            if (i >= k - 1) {
                if (freq.size() == k) {
                    maxSum = std::max(maxSum, currentSum);
                }
                int startElement = nums[i - k + 1];
                currentSum -= startElement;
                freq[startElement]--;
                if (freq[startElement] == 0) {
                    freq.erase(startElement);
                }
            }
        }

        return maxSum;
    }
};
