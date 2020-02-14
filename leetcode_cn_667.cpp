class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        ret.reserve(n);
        for (int i = 1; i <= n - k; ++i) {
            ret.push_back(i);
        }
        bool revers = k % 2 == 0;
        int beg = n - k + 1;
        int end = n;
        while (k) {
            if (k >= 2) {
                ret.push_back(end--);
                ret.push_back(beg++);
                k -= 2;
            } else {
                ret.push_back(end--);
                --k;
            }
        }
        /*
        if (revers) {
            for (int i = end; i >= beg; --i) {
                ret.push_back(i);
            }
        } else {
            for (int i = beg; i <= end; ++i) {
                ret.push_back(i);
            }
        } */
        return ret;
    }
};
