class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty()) return true;
        int sn = s.size();
        int tn = t.size();
        map<char, int> hitMap;
        for (auto x: s) {
                hitMap[x]++;
        }
        for (auto y: t) {
            if (hitMap.find(y) == hitMap.end()) {
                return false;
            }
            else {
                hitMap[y]--;
                if (!hitMap[y])
                    hitMap.erase(y);
            }
                
        }
        if (hitMap.empty())
            return true;
        else
            return false;
    }
};