class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        int m;
        if (nums.empty() || target < nums[0]) {
            return 0;
        }
        if (target > nums.back()) {
            return nums.size();
        }
        while (l < h) {
            m = (h + l) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[m] > target) {
                h = m;
            } else {
                l = m + 1;
            }
        }
        return min(h, l);
    }
};
