class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), 
                [](const vector<int> &v1, const vector<int> &v2) {
                    return v1[1] < v2[1];
                });

        vector<int> piles(envelopes.size(), 1);
        for (size_t i = 1; i != envelopes.size(); ++i) {
            int cnt = 1;
            for (size_t j = 0; j != i; ++j) {
                // if i covers j
                if (envelopes[i][0] > envelopes[j][0] && 
                    envelopes[i][1] > envelopes[j][1]) {
                    cnt = max(cnt, piles[j] + 1);
                }
            }
            piles[i] = cnt;
        }
        int maxCnt = 0;
        for (auto cnt : piles) {
            maxCnt = max(cnt, maxCnt);
        }
        return maxCnt;
    }
};
