class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> tmp;
        tmp.assign(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            nums[(i+k)%n] = tmp[i];
        }
    }
};