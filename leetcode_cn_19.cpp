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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto pior = head;
        ++n;
        while (n && pior) {
            pior = pior->next;
            --n;
        }
        if (n) {
            auto tmp = head;
            head = head->next;
            delete tmp;
            return head;
        }
        auto cur = head;
        while (pior) {
            cur = cur->next;
            pior = pior->next;
        }
        auto tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        return head;
    }
};
