class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int zeroCount = 0;
        for (int& x: nums)
        {
            if (!x)
            {
                if (zeroCount == 1)
                {
                    product = 0;
                    zeroCount++;
                    break;
                }
                else
                {
                    zeroCount++;
                }
            }
            else
            {
                product *= x;
            }
        }
        
        for (int& i: nums)
        {
            if (!i)
            {
                if (zeroCount == 1)
                    i = product;
                else
                    i = 0;
            }
            else
            {
                if (zeroCount > 0)
                    i = 0;
                else
                    i = product/i;
            }
        }
        return nums;
    }
};