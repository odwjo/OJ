class Solution {
public:
    vector<int> rec;

    void recFind(int k, int n, vector<vector<int>> &ret, int start = 1) {
        if (k == 0 && n == 0) {
            ret.push_back(rec);
            return;
        }
        if (k == 0 || n == 0) {
            return;
        }
        for (int i = start; i != 10; ++i) {
            if (i <= n) {
                rec.push_back(i);
                recFind(k - 1, n - i, ret, i + 1);
                rec.pop_back();
            } else {
                break;
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<bool> mark(10, false);
        vector<vector<int>> ret;

        if (n < k || n > k * 9 || n > 81 || k > 9) {
            return ret;
        }

        recFind(k, n, ret);

        return ret;
    }
};
