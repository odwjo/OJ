class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vi(nums.size());
        std::generate(vi.begin(), vi.end(), [n = 0] () mutable { return n++; });
        sort(vi.begin(), vi.end(), [&](int a, int b){ return nums[a] < nums[b]; });

        for (size_t i = 0; i != nums.size() - 1; ++i) {
            size_t low = i + 1;
            size_t high = vi.size() - 1;
            size_t cur = (low + high) / 2;
            auto res = nums[vi[i]] + nums[vi[cur]];
            while (res != target) {
                if (cur == high) {
                    break;
                }
                if (res > target) {
                    high = cur;
                    cur = (low + high) / 2;
                } else {
                    low = cur;
                    cur = (low + high + 1) / 2;
                }
                res = nums[vi[i]] + nums[vi[cur]];
            }
            if (res == target) {
                return { vi[i], vi[cur] };
            }
        }
        return { 0, 0 };
    }
};
