class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1) {
            return s;
        }
        auto size = s.size();
        auto column = size / (2 * numRows - 2);

        string ret;
        auto T = 2 * numRows - 2;
        for (size_t j = 0; j != numRows; ++j) {
            if (j == 0 || j == (numRows - 1)) {
                for (size_t i = j; i < s.size(); i += T) {
                    ret += s[i];
                }
            } else {
                for (size_t i = j; i < s.size(); ) {
                    ret += s[i];
                    i += 2 * (numRows - j - 1);
                    if (i >= s.size()) {
                        break;
                    }
                    ret += s[i];
                    i += 2 * j;
                }
            }
        }
        
        return ret;
    }
};
