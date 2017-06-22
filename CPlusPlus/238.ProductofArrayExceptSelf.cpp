class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);
        int currProduct = 1;
        for (int i = 0; i < n; ++i) {
            ret[i] = currProduct;
            currProduct = nums[i]*currProduct;
        }

        currProduct = 1;
        for (int j = n-1; j >= 0; --j) {
            ret[j] = ret[j] * currProduct;
            currProduct = currProduct*nums[j];
        }
        return ret;

    }
};