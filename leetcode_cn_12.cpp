class Solution {
public:
    string intToRoman(int num) {
        int bits[4] = {0};
        char ones[] = "IXCM";
        char fives[] = "VLD";
        int nb = 0;
        while (num) {
            bits[nb++] = num % 10;
            num /= 10;
        }
        
        string ret;
        while (nb) {
            int tmp = bits[nb - 1];
            if (tmp <= 3) {
                for (size_t i = 0; i != tmp; ++i) {
                    ret += ones[nb - 1];
                }
            } else if (tmp == 4) {
                ret += ones[nb - 1];
                ret += fives[nb - 1];
            } else if (tmp < 9) {
                ret += fives[nb - 1];
                tmp -= 5;
                for (size_t i = 0; i != tmp; ++i) {
                    ret += ones[nb - 1];
                }
            } else {
                ret += ones[nb - 1];
                ret += ones[nb];
            }
            --nb;
        }
        return ret;
    }
};
