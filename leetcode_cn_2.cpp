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
    ListNode* reverse(ListNode *lp) {
        auto prev = lp;
        auto cur = lp->next;
        lp->next = NULL;
        while (cur) {
            auto reserve = cur->next;
            cur->next = prev;
            prev = cur;
            cur = reserve;
        }
        return prev;
    }

    void format(ListNode *p) {
        while (p->next) {
            //when p is long, could overflow
            p->next->val += p->val / 10;
            p->val %= 10;
            p = p->next;
        }
        auto tmp = p->val;
        p->val = tmp % 10;
        tmp /= 10;
        while (tmp) {
            p->next = new ListNode(tmp % 10);
            tmp /= 10;
            p = p->next;
        }
    }

    ListNode* addTwoNumbersXXX(ListNode* l1, ListNode* l2) {
        ListNode *tmp, *head;
        head = new ListNode(l1->val);
        l1 = l1->next;
        tmp = head;
        while (l1) {
            tmp->next = new ListNode(l1->val);
            tmp = tmp->next;
            l1 = l1->next;
        }
        tmp = head;
        while (l2) {
            tmp->val += l2->val;
            l2 = l2->next;
            if (l2 && tmp->next == NULL) {
                tmp->next = new ListNode(0);
            }
            tmp = tmp->next;
        }
        format(head);
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *tmp, *head;
        head = new ListNode(l1->val);
        l1 = l1->next;
        tmp = head;
        while (l1) {
            tmp->next = new ListNode(l1->val);
            tmp = tmp->next;
            l1 = l1->next;
        }
        tmp = head;
        while (l2) {
            auto sum = tmp->val + l2->val;
            tmp->val = sum % 10;
            sum /= 10;
            auto ttmp = tmp;
            while (sum) {
                if (!ttmp->next) {
                    ttmp->next = new ListNode(sum);
                    break;
                }
                sum += ttmp->next->val;
                ttmp->next->val = sum % 10;
                sum /= 10;
                ttmp = ttmp->next;
            }
            l2 = l2->next;
            if (l2 && !tmp->next) {
                tmp->next = new ListNode(0);
            }
            tmp = tmp->next;
        }
        return head;
    }
};
