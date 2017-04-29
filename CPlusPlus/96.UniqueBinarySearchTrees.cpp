class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        if (n == 0)
            return dp[0];
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[i-j-1]*dp[j];
            }
        }
        return dp[n];
    }
};