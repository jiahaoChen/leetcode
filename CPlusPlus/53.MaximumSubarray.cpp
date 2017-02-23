class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (!n)
            return INT_MIN;
        int dp[n];
        int ret = dp[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ret = max(dp[i], ret);
        }
        
        return ret;
    }
};