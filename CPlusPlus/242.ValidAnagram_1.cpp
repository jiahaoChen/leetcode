class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char,int> hitmap;
        for (int i = 0; i < s.length(); ++i) {
            hitmap[s[i]]++;
            hitmap[t[i]]--;
        }
        for (auto x: hitmap)
            if (x.second) return false;
        return true;
    }
};