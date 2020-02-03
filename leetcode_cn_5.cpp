class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }

        string tmpStr(1, s[0]);
        size_t tmpSize = 1;

        size_t d = 1;
        for (size_t i = 0; i != s.size() - 1; ++i) {
            d = 1;
            while (i >= d && ((i + d) < s.size()) && s[i - d] == s[i + d]) {
                ++d;
            }
            if (tmpSize < 2 * d - 1) {
                tmpSize = 2 * d - 1;
                tmpStr = s.substr(i - d + 1, tmpSize);
            }

            d = 1;
            while (i + 1 >= d && (i + d < s.size()) && s[i - d + 1] == s[i + d]) {
                ++d;
            }
            if (tmpSize < 2 * d - 2) {
                tmpSize = 2 * d - 2;
                tmpStr = s.substr(i - d + 2, tmpSize);
            }
        }
        return tmpStr;
    }
};
