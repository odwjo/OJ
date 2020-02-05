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
    void reverse(ListNode* head, ListNode* tail) {
        auto cur = head;
        auto prev = tail->next;
        ListNode* next;
        auto end = tail->next;
        while (cur != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
    }
    ListNode* advc(ListNode* ptr, int k) {
        while (ptr && --k) {
            ptr = ptr->next;
        }
        if (k) {
            return NULL;
        }
        return ptr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto left = head;
        auto right = advc(head, k);
        if (right == NULL) {
            return head;
        }
        head = right;
        auto nleft = right->next;
        reverse(left, right);
        while (1) {
            right = advc(nleft, k);
            if (right == NULL) {
                return head;
            }
            left->next = right;
            left = nleft;
            nleft = right->next;
            reverse(left, right);
        }
    }
};
