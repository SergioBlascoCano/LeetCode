/////////////////////////////////////////////////////////////////////////////////////
// 0242 - Valid Anagram
// Difficulty: EASY
// Exercise: https://leetcode.com/problems/contains-duplicate/description/
// Solution: https://leetcode.com/problems/valid-anagram/submissions/1436611033/
/////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) return false;
        
        std::vector<int> count(26, 0);
        
        for (int i = 0; i < s.size(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] != 0) return false;
        }
        
        return true;
    }
};
