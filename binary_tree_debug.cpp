#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <memory>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class String2Tree {
    TreeNode *root;
    // store all numbers, -1 indicate NULL
    vector<int> nodes;
    string str;

    // INT_MAX indicate null
    int str2int(const string &str, int &start) {
        while (isspace(str[start]) || str[start] == ',' ||
                str[start] == '[' || str[start] == ']') {
            ++start;
        }
        if (str[start] == 'n' ) {
            start += 4;
            return INT_MAX;
        }
        if (str[start] == '#') {
            return INT_MAX;
        }

        bool sign = false;
        int ret = 0;
        if (str[start] == '-') {
            sign = true;
            ++start;
        }
        while (isspace(str[start])) {
            ++start;
        }
        while (isdigit(str[start])) {
            ret += ret * 10 + str[start] - '0';
            ++start;
        }
        //for next
        while (isspace(str[start]) || str[start] == ',' ||
                str[start] == '[' || str[start] == ']') {
            ++start;
        }

        if (sign) {
            ret = -ret;
        }

        return ret;
    }

    void getNodes() {
        int index = 1;
        while (index != str.size()) {
            if (isdigit(str[index]) || str[index] == '-') {
                break;
            }
            ++index;
        }
        int tmp;
        while (index != str.size() - 1) {
            tmp = str2int(str, index);
            nodes.push_back(tmp);
        }
    }

    void buildTree() {
        if (nodes.empty()) {
            root = nullptr;
            return;
        }

        root = new TreeNode(nodes[0]);
        vector<TreeNode *> preLevel(1, root);

        int level = 2;
        int ind = 1;
        while (ind < nodes.size()) {
            int levelCnt = 1 << (level - 1);
            vector<TreeNode *> curLevel;
            int preNodeInd = 0;
            bool isLeft = true;
            for (size_t i = 0; ind < nodes.size() && i != levelCnt; ++i, ++ind) {
                auto val = nodes[ind];
                TreeNode *tmpNode = nullptr;
                if (val != INT_MAX) {
                    tmpNode = new TreeNode(val);
                }
                if (isLeft) {
                    if (preLevel[preNodeInd]) {
                        preLevel[preNodeInd]->left = tmpNode;
                    }
                } else {
                    if (preLevel[preNodeInd]) {
                        preLevel[preNodeInd++]->right = tmpNode;
                    }
                }
                curLevel.push_back(tmpNode);
                isLeft = !isLeft;
                ++level;
            }
            preLevel = curLevel;
        }
    }
public:
    // [2,3,null]
    String2Tree(const string &present): str(present) {
        str += '#'; //mark end

        getNodes();
    }
    TreeNode *getRoot() {
        buildTree();

        return root;
    }
};


////////////////////////// TEST CODE ////////////////////////////

void test(TreeNode *root) {
    if (root == nullptr) {
        return;
    }
    test(root->left);
    cout << root->val << ',';
    test(root->right);

}

int main() {
    auto root = String2Tree("[3,2, 4, null, null, 1]").getRoot();
    test(root);
    return 0;
}
