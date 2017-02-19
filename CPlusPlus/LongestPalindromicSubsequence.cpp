class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[1000][1000];
        dp[0][0] = 1;
        for (int x = 0; x < n; ++x)
        {
            dp[x][x] = 1;
        }
        int i, j, cl;
        for (cl = 2; cl <= n; ++cl)
        {
            for (i = 0; i < n-cl+1;i++)
            {
                j = i+cl-1;
                if (cl == 2)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    if (s[i] == s[j])
                        dp[i][j] = dp[i+1][j-1] + 2;
                    else
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};