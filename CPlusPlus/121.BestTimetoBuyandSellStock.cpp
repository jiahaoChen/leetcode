class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int profit = 0;
        int buy = prices[0];
        for (int i = 1; i < n; ++i) {
            profit = max(profit, prices[i] - buy);
            buy = min(prices[i], buy);
        }
        return profit;
    }
};