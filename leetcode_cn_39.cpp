class Solution {
public:
    vector<int> rec;

    void recFind(vector<int>& candidates, vector<vector<int>> &result, 
                int target, int start = 0) {
        if (target == 0 || candidates.empty()) {
            result.push_back(rec);
            return;
        }

        for (size_t i = start; i != candidates.size(); ++i) {
            if (candidates[i] <= target) {
                rec.push_back(candidates[i]);
                recFind(candidates, result, target - candidates[i], i);
                rec.pop_back();
            }
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        recFind(candidates, ret, target);
        return ret;
    }
};
