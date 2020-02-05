class Solution {
public:
    const vector<string> dic{ "abc", "def", "ghi", "jkl", "mno", "pqrs", 
                            "tuv", "wxyz" };
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) {
            return ret;
        }
        ret.push_back(string());
        for (size_t i = 0; i != digits.size(); ++i) {
            vector<string> tmp;
            for (auto &s : ret) {
                for (auto c : dic[digits[i] - '2']) {
                    tmp.push_back(s + c);
                }
            }
            ret = tmp;
        }
        return ret;
    }
};
