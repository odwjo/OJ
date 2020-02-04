class Solution {
public:
    int reverse(int x) {
        int bits[11] = {0};
        int nb = 0;
        bool isneg = false;
        if (x < 0) {
            if (x == 0x80000000) {
                return 0;
            }
            x = -x;
            isneg = true;
        }
        while (x) {
            bits[nb++] = x % 10;
            x /= 10;
        }

        int ret = 0;
        for (int i = 0; i != nb; ++i) {
            if (ret > ((0x7fffffff) / 10)) {
                ret = 0;
                break;
            }
            ret = ret * 10 + bits[i];
        }
        if (isneg) {
            ret = -ret;
        }
        return ret;
    }
};
