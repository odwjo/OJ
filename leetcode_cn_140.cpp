
class Solution {
public:
    map<int, set<string>> tokens;
    vector<bool> mark;
    vector<string> ret;

    bool inDict(string &s, int sz) {
        return tokens[sz].find(s) != tokens[sz].end();
    }

    bool recFind(string &line, string tmp, size_t pos = 0) {
        if (pos == line.size()) {
            ret.push_back(tmp);
            return true;
        }
        if (pos > line.size()) {
            return false;
        }
        if (!mark[pos]) {
            return false;
        }
        bool flag = false;
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            string s = line.substr(pos, it->first);
            auto tmpFlag = (pos + it->first < line.size()) && mark[pos + it->first];
            tmpFlag = tmpFlag || (pos + it->first == line.size());
            if (tmpFlag && inDict(s, it->first)) {
                if (tmp.empty()) {
                    auto prev = recFind(line, s, pos + it->first);
                    flag = flag || prev;
                } else {
                    auto prev = recFind(line, tmp + ' ' + s, pos + it->first);
                    flag = flag || prev;
                }
            }
        }
        mark[pos] = flag;
        return flag;
    }

    vector<string> wordBreak(string s, vector<string> wordDict) {
        mark = vector<bool>(s.size(), true);
        for (auto &s : wordDict) {
            tokens[s.size()].insert(s);
        }

        recFind(s, "");

        return ret;
    }
};
