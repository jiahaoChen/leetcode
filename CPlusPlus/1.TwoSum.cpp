class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hit;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            if (hit.find(nums[i]) != hit.end() && i != hit[nums[i]]) {
                res.push_back(hit[nums[i]]);
                res.push_back(i);
                return res;
            }
            hit[target - nums[i]] = i;
        }

    }
};