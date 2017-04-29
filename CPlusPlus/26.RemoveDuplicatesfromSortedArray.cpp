class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        vector<int>::iterator iter = nums.begin();
        int preNum = nums[0]-1;
        while (iter != nums.end())
        {
            if (*iter == preNum) {
                preNum = *iter;
                iter = nums.erase(iter);
            }
            else {
                preNum = *iter;
                iter++;
            }
        }
        return nums.size();
    }
};