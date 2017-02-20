class Solution {
public:
    int lengthLongestPath(string input) {
        vector<string> token;
        token = split(input, "\n");
        int *count = new int[token.size()];
        int ret = 0;
        for (string s : token)
        {
            int lev = s.find_last_of("\t") + 1;
            // cout << lev << endl;
            count[lev] = lev==0?s.length():s.length() - lev + count[lev-1] + 1;
            if(s.find(".") != -1)
                ret = max(ret, count[lev]);
            
        }
        return ret;
    }
    
    vector<string> split(string s, string delim)
    {
        auto start = 0;
        vector<string> ret;
        auto end = s.find(delim);
        while (end != std::string::npos)
        {
            ret.push_back(s.substr(start, end - start));
            start = end + delim.length();
            end = s.find(delim, start);
        }
        ret.push_back(s.substr(start, end));
        return ret;
    }
};