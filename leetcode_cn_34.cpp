class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = equal_range(nums.begin(), nums.end(), target);
        int l = -1, h = -1;
        if (range.first != range.second) {
            l = distance(nums.begin(), range.first);
            h = distance(nums.begin(), range.second) - 1;
        }
        return { l, h };
    }
};
