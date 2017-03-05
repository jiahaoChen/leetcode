/*
use Map
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> mp;// need use multiset, because some input string are equal
        for (auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].insert(s);
        }
        vector<vector<string>> rets;
        for (auto m : mp)
        {
            vector<string> ret(m.second.begin(), m.second.end());
            rets.push_back(ret);
        }
        return rets;
    }
};