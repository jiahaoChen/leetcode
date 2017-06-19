class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[curr] = nums[i];
                if (i != curr)
                    nums[i] = 0;
                curr++;
            }
        }
    }
};