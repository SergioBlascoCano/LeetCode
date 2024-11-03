/////////////////////////////////////////////////////////////////////////////////////
// 0796 - Rotate String
// Difficulty: EASY
// Exercise: https://leetcode.com/problems/rotate-string/description/
// Solution: https://leetcode.com/problems/rotate-string/submissions/1441600060
/////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string doubled_s = s + s;
        return doubled_s.find(goal) != string::npos;
    }
};
