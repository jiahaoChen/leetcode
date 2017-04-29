class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ret;
        if (!n) return ret;
        int end = nums[0];
        int start = nums[0];
        string strRet = to_string(start);
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] == end+1) {
                end++;
            }
            else {
                if (start != end)
                    strRet = strRet + "->" + to_string(end);
                ret.push_back(strRet);
                strRet = to_string(nums[i]);
                start = nums[i];
                end = nums[i];
            }
        }
        if (start != end)
            strRet = strRet + "->" + to_string(end);
        ret.push_back(strRet);
        return ret;
    }
};