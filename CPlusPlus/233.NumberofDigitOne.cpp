class Solution {
public:
    int countDigitOne(int n) {
        int highD(n), lowD(0), base(1);
        long long int ret = 0;
        while (highD > 0) {
            int currD = highD%10;
            highD /= 10;
            if (currD == 0) {
                ret += highD*base;
            } else if (currD == 1) {
                ret += highD*base;
                ret += lowD+1;
            } else {
                ret += (highD+1)*base;
            }
            lowD += currD*base;
            base *= 10;
        }
        return ret;
    }
};