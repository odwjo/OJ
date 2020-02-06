class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        } 
        if (n == 1) {
            if (target == nums[0]) {
                return 0;
            } else {
                return -1;
            }
        }
        int h, l, m = 0;
        h = 0; 
        l = n - 1;
        while (h < l) {
            if (l - h < 2) {
                m = nums[l] > nums[h] ? l : h;
                break;
            }
            m = (h + l) / 2;
            if (nums[m] > nums[h]) {
                h = m;
            } else {
                l = m;
            }
        }
        l = (m == nums.size() - 1) ? 0 : m + 1;
        if (target > nums[m] || target < nums[l]) {
            return -1;
        }
        if (target >= nums[0]) {
            if (target == nums[0]) {
                return 0;
            }
            l = 0;
            h = m;
        } else {
            l = m + 1;
            h = nums.size() - 1;    
        }
        auto iter = lower_bound(nums.begin() + l, nums.begin() + h + 1, target);
        auto dis = distance(nums.begin(), iter);
        if (dis != nums.size() && *iter == target) {
            return dis;
        } 
        return -1;
    }
};
