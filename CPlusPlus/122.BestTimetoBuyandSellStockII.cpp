class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1)
            return 0;
        int pre = prices[0];
        int ret = 0;
        for (int i = 1; i < n; ++i)
        {
            ret += max(prices[i] - pre, 0);
            pre = prices[i];
        }
        return ret;
    }
};