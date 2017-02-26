class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        long long base = 5;
        while (n >= base)
        {
            ret += (n/base);
            base*=5;
        }
        return ret;
    }
};