/////////////////////////////////////////////////////////////////////////////////////
// 2275 - Largest Combination With Bitwise AND Greater Than Zero
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/
// Solution: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/submissions/1445719678
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

class Solution {
public:
    int largestCombination(std::vector<int>& candidates) {
        int bit_counts[32] = {0};
        for (int num : candidates) {
            for (int bit = 0; bit < 32; ++bit) {
                if (num & (1 << bit)) {
                    ++bit_counts[bit];
                }
            }
        }
        return *std::max_element(bit_counts, bit_counts + 32);
    }
};
