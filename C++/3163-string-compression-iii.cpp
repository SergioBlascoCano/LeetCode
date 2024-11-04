/////////////////////////////////////////////////////////////////////////////////////
// 3163 - String Compression III
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/string-compression-iii/description/
// Solution: https://leetcode.com/problems/string-compression-iii/submissions/1442555999
/////////////////////////////////////////////////////////////////////////////////////

#include <string>

class Solution {
public:
    std::string compressedString(const std::string& word) {
        std::string comp;
        int n = word.size();
        for (int i = 0; i < n; ) {
            char c = word[i];
            int count = 1;
            while (i + count < n && word[i + count] == c && count < 9) {
                ++count;
            }
            comp += std::to_string(count) + c;
            i += count;
        }
        return comp;
    }
};
