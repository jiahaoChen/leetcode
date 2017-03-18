class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        addPar(ret, "", n, 0);
        return ret;
    }
    
    void addPar(vector<string>& ret, string str, int n, int m)
    {
        if (!n && !m)
            ret.push_back(str);
        if (n>0) addPar(ret, str+"(", n-1, m+1);
        if (m>0) addPar(ret, str+")", n, m-1);
        
    }
};