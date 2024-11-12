/////////////////////////////////////////////////////////////////////////////////////
// 2070 - Most Beautiful Item for Each Query
// Difficulty: MEDIUM
// Exercise: https://leetcode.com/problems/most-beautiful-item-for-each-query/description/
// Solution: https://leetcode.com/problems/most-beautiful-item-for-each-query/submissions/1450539303
/////////////////////////////////////////////////////////////////////////////////////

#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> maximumBeauty(std::vector<std::vector<int>>& items, std::vector<int>& queries) {
        std::sort(items.begin(), items.end());
        
        std::vector<int> prices;
        std::vector<int> beauties;
        
        int max_beauty = 0;
        for (const auto& item : items) {
            max_beauty = std::max(max_beauty, item[1]);
            if (prices.empty() || item[0] != prices.back()) {
                prices.push_back(item[0]);
                beauties.push_back(max_beauty);
            } else {
                beauties.back() = max_beauty;
            }
        }
        
        std::vector<int> answer;
        answer.reserve(queries.size());
        
        for (int q : queries) {
            auto it = std::upper_bound(prices.begin(), prices.end(), q);
            if (it == prices.begin()) {
                answer.push_back(0);
            } else {
                answer.push_back(beauties[it - prices.begin() - 1]);
            }
        }
        
        return answer;
    }
};
