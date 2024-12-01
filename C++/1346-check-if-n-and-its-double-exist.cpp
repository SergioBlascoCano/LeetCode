/////////////////////////////////////////////////////////////////////////////////////
// 1346 - Check If N and Its Double Exist
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/check-if-n-and-its-double-exist/description
// Solution: https://leetcode.com/problems/check-if-n-and-its-double-exist/submissions/1467796196
/////////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool checkIfExist(std::vector<int>& arr) {
        std::unordered_set<int> seen;
        for (int num : arr) {
            if (seen.count(2 * num) || (num % 2 == 0 && seen.count(num / 2))) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
