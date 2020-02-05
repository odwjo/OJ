
class Solution {
public:
    static inline void jumpDupAux(int &m, int inc, vector<int> &n) {
        while (m + inc >= 0 && m + inc != n.size() && n[m] == n[m + inc]) {
            m += inc;
        }
        m += inc;
    }
#define jumpDup(x, inc) jumpDupAux(x, inc, nums)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int i, j, m, n;
        vector<vector<int>> ret;

        if (nums.size() < 4) {
            return ret;
        }

        sort(nums.begin(), nums.end());
        for (i = 0; i != nums.size();) {
            for (j = i + 1; j != nums.size();) {
                m = j + 1; 
                n = nums.size() - 1;
                while (m < n) {
                    if (nums[i] + nums[j] + nums[n] + nums[m] == target) {
                        ret.push_back({ nums[i], nums[j], nums[m], nums[n] });
                        jumpDup(m, 1);
                        jumpDup(n, -1);
                    } else if (nums[i] + nums[j] + nums[n] + nums[m] < target) {
                        jumpDup(m, 1);
                    } else {
                        jumpDup(n, -1);
                    }
                }
                jumpDup(j, 1);
            }
            jumpDup(i, 1);
        }
        return ret;
    }
};
