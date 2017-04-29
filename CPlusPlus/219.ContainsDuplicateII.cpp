class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> hitMap;
        for (int i = 0; i < n; ++i) {
            if (hitMap.find(nums[i]) == hitMap.end())
                hitMap[nums[i]] = i;
            else {
                if (i - hitMap[nums[i]] <= k)
                    return true;
                else
                    hitMap[nums[i]] = i;
            }
        }
        return false;
    }
};