class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1) {
            return s;
        }
        auto size = s.size();
        auto column = size / (2 * numRows - 2);
        vector<size_t> rows(s.size(), 0);
        // T = 2 * numRows - 2
        auto T = 2 * numRows - 2;
        for (size_t j = 0; j != T; ++j) {
            auto row = j % numRows + 1;
            if (j >= numRows) {
                row = numRows - row;
            }
            for (size_t i = j; i < s.size(); i += T) {
                rows[i] = row;
            }
        }
        
        string ret;
        ret.resize(s.size());
        size_t pos = 0;
        for (size_t row = 1; row <= numRows; ++row) {
            for (size_t i = 0; i != s.size(); ++i) {
                if (row == rows[i]) {
                    ret[pos++] = s[i];
                }
            }
        }
        return ret;
    }
};
