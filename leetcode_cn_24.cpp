/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) {
            return NULL;
        }
        auto prev = head;
        auto cur = head;
        auto next = cur->next;
        auto nnext = head;
        if (next) {
            nnext = next->next;
            head = next;
            next->next = cur;
            cur->next = nnext;
            prev = cur;
            cur = cur->next;
        }

        while (cur && cur->next) {
            next = cur->next;
            prev->next = next;
            nnext = next->next;
            next->next = cur;
            cur->next = nnext;
            prev = cur;
            cur = nnext;
        }
        return head;
    }
};
