class Solution {
public:
    vector<bool> mark;
    vector<vector<int>> ret;
    vector<int> tmp;
    void gen(vector<int> nums) {
        if (tmp.size() == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        for (size_t i = 0; i != nums.size(); ++i) {
            if (mark[i] || (i != 0 && nums[i] == nums[i - 1] && !mark[i - 1])) {
                continue;
            }
            tmp.push_back(nums[i]);
            mark[i] = true;
            gen(nums);
            tmp.pop_back();
            mark[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        mark = vector<bool> (nums.size(), false);

        gen(nums);

        return ret;
    }
};
