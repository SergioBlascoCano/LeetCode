/////////////////////////////////////////////////////////////////////////////////////
// 0023 - Merge k Sorted Lists
// Difficulty: HARD
// Exercise: https://leetcode.com/problems/merge-k-sorted-lists/description/
// Solution: https://leetcode.com/problems/merge-k-sorted-lists/submissions/1458058576
/////////////////////////////////////////////////////////////////////////////////////

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(compare)> pq(compare);
        
        for (ListNode* list : lists) {
            if (list) pq.push(list);
        }
        
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            if (node->next) pq.push(node->next);
        }
        
        return dummy->next;
    }
};
