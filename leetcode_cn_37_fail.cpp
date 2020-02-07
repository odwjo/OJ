class Solution {
public:
    vector<vector<int>> cnt;
    vector<set<int>> hset;
    vector<set<int>> vset;
    vector<set<int>> gset;
    int needFill ;
    vector<vector<vector<int>>> rec;
    vector<int> full;
    Solution(): full({ 1, 2, 3, 4, 5, 6, 7, 7, 8, 9 }){
        cnt = vector<vector<int>>(9, vector<int>(9));
        hset = vector<set<int>> (9);
        vset = vector<set<int>> (9);
        gset = vector<set<int>> (9);
        needFill = 81;
        rec = vector<vector<vector<int>>> (9, vector<vector<int>>(9, vector<int>(9)));
    }

    //fill(board, i, j, rec, needFail, cnt);
    void fill(vector<vector<char>>& board, int i, int j) {
        --needFill;
        cnt[i][j] = 0;
        vector<int> vi(9);
        int gx = i / 3 * 3;
        int gy = j / 3 * 3;
        int num = 0;
        for (int inc = 0; inc != 9; ++inc) {
            if (rec[i][j][inc] == 0) {
                num = inc;
                break;
            }
        }
        board[i][j] = num + '1';
        for (int inc = 0; inc != 9; ++inc) {
            if (rec[i][inc][num] == 0) {
                --cnt[i][inc];
                rec[i][inc][num] = 1;
            }
            if (rec[inc][j][num] == 0) {
                --cnt[inc][j];
                rec[inc][j][num] = 1;
            }
            auto gi = gx + inc / 3;
            auto gj = gy + inc % 3;
            if (rec[gi][gj][num] == 0) {
                --cnt[gi][gj];
                rec[gi][gj][num] = 1;
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                cnt[i][j] = 9;
            }
        }
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                auto c = board[i][j];
                if (c != '.') {
                    hset[i].insert(c - '1');
                    vset[j].insert(c - '1');
                    gset[(j / 3) * 3 + i / 3].insert(c - '1');
                    cnt[i][j] = 0;
                    --needFill;
                }
            }
        }
        
        for (int i = 0; i != 9; ++i) {
            for (int j = 0; j != 9; ++j) {
                if (cnt[i][j] <= 0) {
                    continue;
                }
                int tmp[9] = {0};
                int tmp2[9] = {0};
                auto p = set_union(hset[i].begin(), hset[i].end(),
                            vset[j].begin(), vset[j].end(), tmp);
                auto pos = set_union(tmp, p, gset[(j / 3) * 3 + i / 3].begin(),
                            gset[(j / 3) * 3 + i / 3].end(), tmp2);
                int *tmpp = tmp2;
                while (tmpp != pos) {
                    rec[i][j][*tmpp] = 1;
                    --cnt[i][j];
                    ++tmpp;
                }
            }
        }

        while (needFill) {
            for (int i = 0; i != 9; ++i) {
                for (int j = 0; j != 9; ++j) {
                    if (cnt[i][j] == 1) {
                        fill(board, i, j);
                    }
                }
            }
        }
    }
};
