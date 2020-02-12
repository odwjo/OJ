class Solution {
public:
    vector<bool> colMark;
    vector<bool> leftDiaMark;
    vector<bool> rightDiaMark;
    vector<vector<string>> ret;
    vector<string> rec;
    int queens;

    void recFind(int i = 0 /*curRow*/) {
        if (i == queens) {
            ret.push_back(rec);
            return;
        }

        for (int j = 0; j != queens; ++j) {
            if (colMark[j] || leftDiaMark[i + j] || 
                rightDiaMark[i - j + queens - 1]) {
                continue;
            }
            colMark[j] = leftDiaMark[i + j] = rightDiaMark[i - j + queens - 1] = true;
            rec[i][j] = 'Q';
            recFind(i + 1);
            rec[i][j] = '.';
            colMark[j] = leftDiaMark[i + j] = rightDiaMark[i - j + queens - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        queens = n;
        colMark = vector<bool>(n, false);
        leftDiaMark = vector<bool>(2 * n - 1, false);
        rightDiaMark = vector<bool>(2 * n - 1, false);
        rec = vector<string>(n, string(n, '.'));

        recFind(0);

        return ret;
    }
};
