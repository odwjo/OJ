class Solution {
public:
    int longestValidParentheses(string s) {
        int i = 0;
        vector<int> cnts(s.size());
        int maxCnt = 0;
        int tmpCnt = 0;
        for (int p = 0; p != s.size(); ++p) {
            if (s[p] == ')') {
                if (i != 0) {
                    --i;
                    if (s[p - 1] == '(') {
                        cnts[p] = 2;
                    } else {
                        cnts[p] = 1;
                    }
                }
            } else {
                ++i;
            }
        }
        for (int i = s.size() - 1; i > 0; --i) {
            int j = i;
            tmpCnt = 0;
            int stk = 0;
            while (j > 0 && cnts[j]) {
                ++tmpCnt;
                if (cnts[j] == 1) {
                    ++stk;
                    --j;
                } else {
                    j -= cnts[j];
                    while (j > 0 && cnts[j] == 0 && stk) {
                        --j;
                        --stk;
                    }
                } //(()) ((()()))
            }
            maxCnt = max(maxCnt, tmpCnt);
            i = j;
        }
        return maxCnt * 2;


    }
};
