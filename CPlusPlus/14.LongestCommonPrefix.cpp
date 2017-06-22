class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ret = "";
        if (!n) return ret;
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 0; j < n; ++j) {
                if (strs[0][i] != strs[j][i])
                    return ret;
            }
            ret += strs[0][i];
        }
        return ret;
    }
};