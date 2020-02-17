class Solution {
    int halfRingSize;
    int curPos;
    vector<set<int>> charPos;
    void preDealRing(const string &s) {
        for (size_t i = 0; i != s.size(); ++i) {
            charPos[s[i] - 'a'].insert(i);
        }
    }
public:
    Solution(): charPos(26) {}

    int findRotateSteps(string ring, string key) {
        preDealRing(ring);
        curPos = 0;
        halfRingSize = ring.size() / 2;
        vector<int> rec;
		map<int, int> curPos;
		curPos[0] = 0;
        for (auto c : key) {
			map<int, int> newRec;
			for (auto iter = curPos.begin(); iter != curPos.end(); ++iter) {
                auto cur = iter->first;
				for (auto i : charPos[c - 'a']) {
					int step = 1;
					if (i != cur) {
					    int dis = i < cur ? (cur - i) : (i - cur);
					    step += dis > halfRingSize ? ring.size() - dis : dis;
                    }
					if (newRec.find(i) != newRec.end()) {
						newRec[i] = min(newRec[i], step + iter->second);
					} else {
						newRec[i] = step + iter->second;
					}
				}
			}
			curPos = newRec;
        }
		
		int ret = INT_MAX;
		for (auto iter : curPos) {
			ret = min(ret, iter.second);
		}
		return ret;
    }
};
