class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i)
            ret = ret*26 + (int)s[i] - 64;
        return ret;
    }
};