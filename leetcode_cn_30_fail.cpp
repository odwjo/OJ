

class Solution {
public:
    vector<string> stripes;
    set<int> tmp;

    bool zarrayMatch(string &s, string sub) {
        int subSize = sub.size();
        sub += '#';
        sub += s;
        int n = sub.size();
        vector<int> z(n, 0);
        int x = 0;
        int y = 0;
        for (int i = 1; i != n; ++i) {
            // if i > y : 0 else z[i - x]
            z[i] = max(0, min(z[i - x], y - i + 1));
            // update [x, y] if we can
            while (i + z[i] < n && sub[z[i]] == sub[i + z[i]]) {
                x = i; //i >= x
                y = i + z[i]; //[0, y - x] == [x, y]
                ++z[i]; // ++cnt
                // here we go
                if (z[i] == subSize) {
                    tmp.insert(i - subSize - 1);
                }
            }
        }
        return tmp.empty();
    }

    void genStripe(vector<string> &words, vector<bool> &choose, 
                    string tmp = string(), size_t c = 0) {
        if (c == words.size()) {
            stripes.push_back(tmp);
            return;
        }
        for (size_t i = 0; i != words.size(); ++i) {
            if (choose[i]) {
                continue;
            }
            choose[i] = true;
            genStripe(words, choose, tmp + words[i], c + 1);
            choose[i] = false;
        }
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<string> combine;
        vector<bool> choose(words.size(), false);
        genStripe(words, choose);

        for (auto &sub : stripes) {
            zarrayMatch(s, sub);
        }
        return vector<int>(tmp.begin(), tmp.end());
    }
};
