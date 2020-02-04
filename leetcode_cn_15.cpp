bool vec_eq(const vector<int> &v1, const vector<int> &v2) {
    return v1[0] == v2[0] && v1[1] == v2[1];
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3) {
            return ret;
        } else if (nums.size() == 3) {
            if (nums[0] + nums[1] + nums[2] == 0) {
                return { nums };
            } else {
                return ret;
            }
        }

        
        for (size_t i = 0; i != nums.size() && nums[i] <= 0;) {
            auto iter = nums.end();
            auto iprev = nums[i];
            for (size_t j = i + 1; j != nums.size(); ) {
                if (nums[i] + nums[j] > 0) {
                    break;
                }
                auto jprev = nums[j];
                if (nums.back() < (-nums[i] - nums[j])) {
                    ++j;
                    continue;
                }
                if (iter <= nums.begin() + j + 1) {
                    break;
                }
                iter = lower_bound(nums.begin() + j + 1, iter, 
                                    -nums[i] - nums[j]);
                if (iter != nums.end() && *iter == (-nums[i] - nums[j])) {
                    vector<int> tmp{ nums[i], nums[j], *iter };
                    if (ret.empty() || !vec_eq(tmp, ret.back())) {
                        ret.push_back(tmp);
                    }
                }
                while (++j != nums.size() && nums[j] == jprev) {
                    ;
                }
            }
            while (++i != nums.size() && nums[i] == iprev) {
                ;
            }
        }
        return ret;
    }
};
