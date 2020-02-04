class Solution {
public:

    bool isMatch(string s, string p) {
        size_t sPos ,pPos;
        sPos = pPos = 0;
        if (pPos == p.size() && sPos == s.size()) {
            return true;
        } else if (p.size() == 0) {
            return false;
        } else if (s.size() == 0) {
            if (p.size() % 2) {
                return false;
            }
            size_t i = 0;
            for (; i + 1 < p.size() && p[i + 1] == '*'; i += 2) {
            }
            if (i == p.size()) {
                return true;
            } else {
                return false;
            }
        }
        auto token = p[pPos];
        if (p[pPos] == '.') {
            if (pPos != p.size() - 1) {
                if (p[pPos + 1] == '*') {
                    if (pPos == p.size() - 2) {
                        return true;
                    }
                    for (size_t pos = sPos; pos <= s.size(); ++pos) {
                        if (isMatch(s.substr(pos), p.substr(pPos + 2))) {
                            return true;
                        }
                    }
                    return false;
                } else {
                    return isMatch(s.substr(sPos + 1), p.substr(pPos + 1));
                }
            } else {
                return sPos == s.size() - 1;
            }
        } else {
            if (pPos != p.size() - 1) {
                if (p[pPos + 1] == '*') {
                    size_t pos = sPos;

                    while (pos <= s.size()) {
                        if (isMatch(s.substr(pos), p.substr(pPos + 2))) {
                            return true;
                        }
                        if (pos != s.size() && s[pos] == p[pPos]) {
                            ++pos;
                        } else {
                            break;
                        }
                    }

                    if (pos == s.size()) {
                        return p.size() == pPos + 2;
                    }
                    return false;
                } else {
                    if (s[sPos] == p[pPos]) {
                        return isMatch(s.substr(sPos + 1), p.substr(pPos + 1));
                    } else {
                        return false;
                    }
                }
            } else {
                return (!s.empty()) && (sPos == s.size() - 1) && p[pPos] == s.back();
            }
        }
    }
};
