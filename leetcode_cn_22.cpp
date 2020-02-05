class Solution {
public:
    vector<string> ret;
    string tmp;
    void recGen(int left, int right) {
        if (left == 0 && right == 0) {
            ret.push_back(tmp);
            return;
        }
        if (left) {
            tmp.push_back('(');
            recGen(left - 1, right + 1);
            tmp.pop_back();
        } 
        if (right) {
            tmp.push_back(')');
            recGen(left, right - 1);
            tmp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        recGen(n, 0);
        return ret;
    }
};
