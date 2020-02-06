class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int fs = 10;
        for (int i = 0; i != 9; ++i) {
            vector<int> h(fs, 0), v(fs, 0);
            for (int j = 0; j != 9; ++j) {
                auto hc = board[i][j];
                auto vc = board[j][i];
                if (hc != '.') {
                    if (h[hc - '0'] != 0) {
                        return false;
                    } else {
                        h[hc - '0'] = 1;
                    }
                }
                if (vc != '.') {
                    if (v[vc - '0'] != 0) {
                        return false;
                    } else {
                        v[vc - '0'] = 1;
                    }
                }
            }
        }
        for (int i = 0; i != 9; i += 3) {
            for (int j = 0; j != 9; j += 3) {
                vector<int> a(fs, 0);
                for (int h = i; h != i + 3; ++h) {
                    for (int v = j; v != j + 3; ++v) {
                        auto c = board[h][v];
                        if (c != '.') {
                            if (a[c - '0'] != 0) {
                                return false;
                            } else {
                                a[c - '0'] = 1;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
