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
    vector<string> ret;
    vector<TreeNode*> rec;
    vector<bool> mark;
    char buf[12];

    void recPrint(TreeNode *node) {
        if (node->left == NULL && node->right == NULL) {
            ostringstream ss;
            if (!rec.empty()) {
                size_t i = 0;
                ss << rec[i++]->val;
                for (;i != rec.size(); ++i) {
                    ss << "->" << rec[i]->val;
                }
                ss << "->" << node->val;
            } else {
                ss << node->val;
            }
            ret.push_back(ss.str());
            return ;
        }
        rec.push_back(node);
        if (node->left) {
            recPrint(node->left);
        }
        if (node->right) {
            recPrint(node->right);
        }
        rec.pop_back();
    }

    void recPrint(TreeNode *node, string trace) {
        sprintf(buf, "%d", node->val);
        trace += buf;
        if (node->left == NULL && node->right == NULL) {
            ret.push_back(trace);
            return;
        }
        trace += "->";
        if (node->left) {
            recPrint(node->left, trace);
        }
        if (node->right) {
            recPrint(node->right, trace);
        }
    }

    void printRec(TreeNode* node) {
        ostringstream ss;
        size_t i = 0;
        ss << rec[i++]->val;
        for (;i != rec.size(); ++i) {
            if (mark[i])
                ss << "->" << rec[i]->val;
        }
        
        ret.push_back(ss.str());
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL) {
            return ret;
        }
        //recPrint(root);
        //recPrint(root, "");
        rec.push_back(root);
        mark.push_back(false);
        while (!rec.empty()) {
            if (mark.back()) {
                rec.pop_back();
                mark.pop_back();
                continue;
            }
            auto node = rec.back();
            if (node->left == NULL && node->right == NULL) {
                mark.back() = true;
                printRec(node);
                rec.pop_back();
                mark.pop_back();
            } else {
                mark.back() = true;
                if (node->left) {
                    rec.push_back(node->left);
                    mark.push_back(false);
                }
                if (node->right) {
                    rec.push_back(node->right);
                    mark.push_back(false);
                }
            }
        }
        return ret;
    }
};
