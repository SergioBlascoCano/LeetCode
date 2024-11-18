/////////////////////////////////////////////////////////////////////////////////////
// 1652 - Defuse the Bomb
// Difficulty: EASY
// Exercise: https://leetcode.com/problems/defuse-the-bomb/submissions/
// Solution: https://leetcode.com/problems/defuse-the-bomb/submissions/1456009432
/////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    std::vector<int> decrypt(std::vector<int>& code, int k) {
        int n = code.size();
        std::vector<int> result(n, 0);

        if (k == 0) {
            return result;
        }

        int start = 1, end = k;
        if (k < 0) {
            start = n + k;
            end = n - 1;
            k = -k;
        }

        int windowSum = 0;
        for (int i = start; i <= end; ++i) {
            windowSum += code[i % n];
        }

        for (int i = 0; i < n; ++i) {
            result[i] = windowSum;
            windowSum -= code[(i + start) % n];
            windowSum += code[(i + start + k) % n];
        }

        return result;
    }
};
