class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        
        size_t flags[256] = {0};
        int ret = 1;
        flags[s[0]] = 1;
        size_t prevPos = 0;
        int tmpLength = 1;
        for (size_t i = 1; i < s.size(); ++i) {
            if (flags[s[i]]) {
                prevPos = max(flags[s[i]], prevPos);
            }
            ret = max<int>(ret, i - prevPos + 1);
            flags[s[i]] = i + 1;
        }
        ret = max<size_t>(ret, s.size() - prevPos);
        return ret;
    }
};
