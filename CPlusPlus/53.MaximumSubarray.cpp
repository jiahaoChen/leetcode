class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int leftMax = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            leftMax = leftMax>0? leftMax+nums[i]: nums[i];
            maxSub = max(maxSub,  leftMax);
        }

        return maxSub;
    }
};