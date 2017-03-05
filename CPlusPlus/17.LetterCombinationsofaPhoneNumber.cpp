/*
two for loop to connect two difference group 
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) return ret;
        static vector<string> vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        ret.push_back("");
        for (int i = 0; i < digits.size(); ++i)
        {
            int num = digits[i]-'0'; // P.S. convert char nums to int nums
            if (num < 0 || num > 9) break;
            const string& candidate = vec[num];
            if (candidate.empty()) continue;
            vector<string> tmp;
            for (int j = 0; j < candidate.size(); ++j)
            {
                for (int k = 0; k < ret.size(); ++k)
                {
                    tmp.push_back(ret[k]+candidate[j]);
                }
            }
            ret.swap(tmp); // vector swap ret and tmp
        }
        return ret;
        
    }
};