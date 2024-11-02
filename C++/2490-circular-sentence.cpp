/////////////////////////////////////////////////////////////////////////////////////
// 2490 - Circular Sentence
// Difficulty: EASY
// Exercise: https://leetcode.com/problems/circular-sentence/description/
// Solution: https://leetcode.com/problems/circular-sentence/submissions/1440637824
/////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        if (n == 1) {
            return sentence[0] == sentence[n - 1];
        }
        if (sentence[n - 1] != sentence[0]) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (sentence[i] == ' ') {
                if (sentence[i - 1] != sentence[i + 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
