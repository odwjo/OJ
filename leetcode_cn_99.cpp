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
    TreeNode *pre;
    TreeNode *rec;
    TreeNode *recNext;
    bool flag;
public:
    Solution(): pre(nullptr), rec(nullptr), recNext(nullptr), flag(false) {}
    void recRecoverTree(TreeNode* root) {
        if (root == nullptr || flag) {
            return;
        }
        recRecoverTree(root->left);
        if (pre && rec == nullptr && root->val < pre->val) {
            rec = pre;
            recNext = root;
        } else if (pre && root->val < pre->val) {
            auto tmp = root->val;
            root->val = rec->val;
            rec->val = tmp;
            flag = true;
            return;
        }
        pre = root;
        recRecoverTree(root->right);
    }
    void recoverTree(TreeNode* root) {
        recRecoverTree(root);
        if (!flag) {
            auto tmp = rec->val;
            rec->val = recNext->val;
            recNext->val = tmp;
        }
        return;
    }
};
