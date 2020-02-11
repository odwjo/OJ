class Solution {
public:
    int sz;
	vector<string> ret;
	vector<int> lengthRec;

    Solution(): sz(0) {}

    bool judge(string &s, int starts, int inc, int leftSeg) {

        if (starts + inc > sz || sz - starts - inc > leftSeg * 3) {
                    return false;
        }
        if (inc != 1 && s[starts] == '0') {
            return false;
        }
        if (inc == 3) {
            switch (s[starts]) {
                case '2':
                    if (!(s[starts + 1] < '5' ||
                        (s[starts + 1] == '5' && s[starts + 2] < '6'))) {
                        return false;
                    }
                    break;
                case '1':
                    break;
                default:
                    return false;
            }
        }
        return true;
    }

	void recFind(string &s, int starts = 0, int Segnum = 4) {
        if (starts == sz && Segnum != 0) {
            return;
        }
		if (Segnum == 0) {
			int i = 0;
            string tmp;
			for (auto n : lengthRec) {
				tmp += s.substr(i, n);
                tmp += '.';
				i += n;
			}
            tmp.pop_back();
			ret.push_back(tmp);
            return;
		}
        if (Segnum == 1) {
            if (judge(s, starts, sz - starts, 0)) {
                lengthRec.push_back(sz - starts);
                recFind(s, sz, 0);
                lengthRec.pop_back();
            }
            return;
        }
		for (int i = 1; i != 4; ++i) {
			if (!judge(s, starts, i, Segnum - 1)) {
				continue;
			}
			lengthRec.push_back(i);
			recFind(s, starts + i, Segnum - 1);
			lengthRec.pop_back();
		}
		return;
	}

    vector<string> restoreIpAddresses(string s) {
        sz = s.size();

		recFind(s);

		return ret;
    }
};
