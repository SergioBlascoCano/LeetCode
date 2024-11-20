/////////////////////////////////////////////////////////////////////////////////////
// 0025 - Reverse Nodes in k-Group
// Difficulty: HARD
// Exercise: https://leetcode.com/problems/reverse-nodes-in-k-group/description/
// Solution: https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/1458612361
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prevGroupEnd = dummy;

        while (true) {
            ListNode* groupStart = prevGroupEnd->next;
            ListNode* groupEnd = prevGroupEnd;
            for (int i = 0; i < k && groupEnd; ++i) {
                groupEnd = groupEnd->next;
            }
            if (!groupEnd) break;

            ListNode* nextGroupStart = groupEnd->next;
            groupEnd->next = nullptr;

            ListNode* prev = nullptr;
            ListNode* curr = groupStart;
            while (curr) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            prevGroupEnd->next = prev;
            groupStart->next = nextGroupStart;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};
