class Solution {
public:
    string countAndSay(int n) {
        if (!n) return "";
        string ret = "1";
        string curr = "1";
        for (int i = 1; i < n; ++i) {
            int len = curr.size();
            ret = "";
            for (int j = 0; j < len; j++) {
                int count = 1;
                while (j+1 < len && curr[j] == curr[j+1]) {
                    count++;
                    j++;
                }
                ret = ret + to_string(count) + curr[j];
            }
            curr = ret;
        }
        return ret;
    }
};