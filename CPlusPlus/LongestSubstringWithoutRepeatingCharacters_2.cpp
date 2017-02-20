class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int start = -1;
        int maxLen = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (hash.find(s[i]) != hash.end() && hash[s[i]] > start)
            {
                start = hash[s[i]];
            }
            hash[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};