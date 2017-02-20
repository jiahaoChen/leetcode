class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        string ret = "";
        string tmp = "";
        for (int i = 0; i < s.size(); ++i)
        {
            size_t index = tmp.find(s[i]);
            if (index == string::npos)
            {
                tmp+=s[i];
                if(tmp.size() > ret.size())
                    ret = tmp;
            }
            else
            {
                tmp = tmp.substr(index+1);
                tmp+=s[i];
            }
        }
        return ret.size();
    }
};