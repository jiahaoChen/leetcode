class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxN, minN, ret;
        maxN = minN = ret = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int tmp = maxN;
            maxN = max({minN*nums[i], maxN*nums[i], nums[i]});
            minN = min({minN*nums[i], tmp*nums[i], nums[i]});
            ret = max(maxN, ret);
        }
        return ret;
    }
};