class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2) {
            return;
        }
        int j;
        int i = nums.size() - 1;
        bool flag = false;
        for (; i != 0; --i) {
            if (nums[i] > nums[i - 1]) {
                j = i;
                --i;
                while (j != nums.size()) {
                    if (nums[j] <= nums[i]) {
                        break;
                    }
                    ++j;
                }
                --j;
                swap(nums[i], nums[j]);
                flag = true;
                break;
            }
        }
        if (!flag) {
            reverse(nums.begin(), nums.end());
        } else {
            reverse(nums.begin() + i + 1, nums.end());
        }
        
        return;
    }
};
