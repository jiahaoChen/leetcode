class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 1;
        if (n <= 2) return n;
        int ret[3] = {1,2,0};
        for (int i = 3; i < n+1; ++i) {
            ret[2] = ret[0] + ret[1];
            ret[0] = ret[1];
            ret[1] = ret[2];
        }
        return ret[2];
    }
};