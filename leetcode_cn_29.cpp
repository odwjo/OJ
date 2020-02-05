class Solution {
public:
    using Judge = function<bool(int)>;
    int getCount(int did, int dis, Judge judge) {
        vector<int> diss;
        vector<int> rets;
        int cnt = 1;
        int ret = 0;
        while (judge(did + dis)) {
            diss.push_back(dis);
            rets.push_back(cnt);
            if ((dis < 0 && INT_MIN - dis > dis) || 
                    (dis > 0 && INT_MAX - dis < dis)) {
                break;
            }
            dis += dis;
            cnt += cnt;
        }
        int i = diss.size() - 1;
        while(i >= 0) {
            if (judge(did + diss[i])) {
                did += diss[i];
                ret += rets[i];
            } else {
                --i;
            }
        }
        return ret;
    }
    //将两个数变为异号，然后加
    int divide(int dividend, int divisor) {
        int ret = 0;
        if (dividend == 0) {
            return ret;
        }
        if (divisor == 1) {
            return dividend;
        }
        bool neg = (dividend < 0 ? divisor > 0 : divisor < 0);
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            }
            if (divisor == INT_MIN) {
                return 1;
            }
        } 
        if (divisor == INT_MIN) {
            return 0;
        }
        if (!neg) {
            divisor = -divisor;
        }
        
        if (dividend == -divisor) {
            ret = 1;
        } else if (dividend < 0) {
            ret += getCount(dividend, divisor, [](int a){ return a <= 0; });
        } else {
            ret += getCount(dividend, divisor, [](int a){ return a >= 0; });
        }
        if (neg) {
            ret = -ret;
        }
        return ret;
    }
};
