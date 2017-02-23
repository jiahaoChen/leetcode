class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (strs.size() < 1)
            return "";
        int len = strs[0].size();
        for (int i = 1; i < n; ++i)
        {
            int tmp = len;
            len = 0;
            for (int j = 0; j < strs[i].size() && j < tmp; ++j)
            {
                if (strs[i][j] == strs[0][j])
                    len++;
                else
                    break;
            }
            if (!len)
                break;
        }
        return strs[0].substr(0,len);
    }
};