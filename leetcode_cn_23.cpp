/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct NodeCmp {
    bool operator()(const ListNode *l1, const ListNode *l2) const {
        return l1->val > l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heads;
        for (auto np : lists) {
            if (np) {
                heads.push_back(np);
            }
        }
        if (heads.empty()) {
            return NULL;
        }
        
        make_heap(heads.begin(), heads.end(), NodeCmp());
        
        pop_heap(heads.begin(), heads.end(), NodeCmp());
        auto head = heads.back();
        heads.pop_back();

        if (head->next) {
            heads.push_back(head->next);
            push_heap(heads.begin(), heads.end(), NodeCmp());
        }
        auto cur = head;
        while (!heads.empty()) {
            pop_heap(heads.begin(), heads.end(), NodeCmp());
            auto node = heads.back();
            heads.pop_back();

            cur->next = node;
            cur = node;
            if (node->next) {
                heads.push_back(node->next);
                push_heap(heads.begin(), heads.end(), NodeCmp());
            }
        }
        return head;
    }
};
