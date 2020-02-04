class Solution {
public:
    int trap(vector<int>& h) {
        auto res = 0;
        if (h.size() < 2) {
            return 0;
        }
        size_t i = 0, j = h.size() - 1;
        int left = 0, right = 0;
        while (i != j) {
            if (h[i] < left) {
                res += left - h[i];
            } else {
                left = h[i];
            }
            if (h[j] < right) {
                res += right - h[j];
            } else {
                right = h[j];
            }
            if (h[j] > h[i]) {
                ++i;
            } else {
                --j;
            }
        }
        return res;
    }
};
