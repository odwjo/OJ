/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历第k个元素
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        while (!stk.empty() || cur != NULL) {
            while (cur != NULL) {
                stk.push(cur);
                cur = cur->left;
            }
            auto node = stk.top();
            stk.pop();
            --k;
            if (k == 0) {
                return node->val;
            }
            cur = node->right;
        }
        return -1;
    }
};
