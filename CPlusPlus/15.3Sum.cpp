/*
1. sort nums
2. set a targe number [0...n]
3. move start=1 ->  <- end=n-1
4. one targe not only one ret, need start++, end-- to find other
5. targe if the same need targe++ to avoid same ret  
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ret;
        if(n < 3) return ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size();++i) {
            int start = i+1;
            int end = n-1;
            int hit = -nums[i];
            while (start < end) {
                int sum = nums[start]+nums[end];
                if (sum > hit) {
                    end--;  
                } else if(sum < hit) {
                    start++;
                } else {
                    ret.push_back({nums[i], nums[start], nums[end]});
                    start++;
                    end--;
                    while(start < end && nums[start] == nums[start-1]) start++;
                    while(start < end && nums[end] == nums[end+1]) end--;
                }
                
            }
            while (i+1 < n && nums[i] == nums[i+1]) ++i;
        }
        return ret;
    }
};