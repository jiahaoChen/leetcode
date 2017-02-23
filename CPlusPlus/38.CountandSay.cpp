class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        if (n <= 1)
            return ret;
        int count = 1;
        for (int i = 1; i < n; ++i)
        {
            string curr = ret;
            ret = "";
            for (int j = 0; j < curr.size(); ++j)
            {
                if (j+1 == curr.size() || curr[j] != curr[j+1])
                {
                    ret += to_string(count);
                    ret += curr[j];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
        }
        return ret;
    }
};