class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // this method is more faster, and P.S. the static function implement
        // [](string &s1, string &s2){ return s1+s2>s2+s1; }
        // vector<string> arr;
        // for(auto i:num)
        //     arr.push_back(to_string(i));
        // sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2>s2+s1; });
        sort(nums.begin(), nums.end(), sortAlgorithm);
        string s = "";
        for (int x: nums)
        {
            s += to_string(x);
        }
        if (s[0] == '0')
            return "0";
        else
            return s;
    }
    static bool sortAlgorithm(int a, int b)
    {
        string stra = to_string(a);
        string strb = to_string(b);
        return stra+strb>strb+stra;
    }
};