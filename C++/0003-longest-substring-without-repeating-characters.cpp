/////////////////////////////////////////////////////////////////////////////////////
// 0003 - Longest Substring Without Repeating Characters
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Solution: https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/1442133318
/////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); ++end) {
            char currentChar = s[end];
            
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
                start = charIndexMap[currentChar] + 1;
            }
            
            charIndexMap[currentChar] = end;
            maxLength = std::max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};
