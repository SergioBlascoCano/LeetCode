/////////////////////////////////////////////////////////////////////////////////////
// 2516 - Take K of Each Character From Left and Right
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/
// Solution: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/submissions/1458046152
/////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int takeCharacters(std::string s, int k) {
        int n = s.size();
        std::vector<int> totalCount(3, 0);

        for (char c : s) {
            totalCount[c - 'a']++;
        }

        if (totalCount[0] < k || totalCount[1] < k || totalCount[2] < k) {
            return -1;
        }

        std::vector<int> windowCount(3, 0);
        int left = 0, maxMiddle = 0;

        for (int right = 0; right < n; ++right) {
            windowCount[s[right] - 'a']++;

            while (windowCount[0] > totalCount[0] - k ||
                   windowCount[1] > totalCount[1] - k ||
                   windowCount[2] > totalCount[2] - k) {
                windowCount[s[left] - 'a']--;
                left++;
            }

            maxMiddle = std::max(maxMiddle, right - left + 1);
        }

        return n - maxMiddle;
    }
};
