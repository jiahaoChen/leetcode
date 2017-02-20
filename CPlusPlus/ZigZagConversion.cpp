class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string *sp = new string[numRows];
        string ret = "";
        int step = 1;
        int row = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i)
        {
            sp[row] += s[i];
            if(row == 0)
                step = 1;
            else if(row == numRows-1)
                step = -1;
            row += step;
        }
        for (int j = 0; j < numRows; ++j)
        {
            ret += sp[j];
        }
        delete [] sp;
        return ret;
    }
};