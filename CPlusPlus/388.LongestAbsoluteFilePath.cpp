class Solution {
public:
    int lengthLongestPath(string input) {
        int count = 0;
        int maxLen = 0;
        int currLevel = 1;
        vector<int> level(200);
        int n = input.size();
        bool isFile = false;
        for (int i = 0; i < n; ++i) {
            while (input[i] == '\t' && i < n) {
                ++currLevel; ++i;
            }
            while (input[i] != '\n' && i < n) {
                if (input[i] == '.') isFile = true;
                ++count; ++i;
            }
            if (isFile) {
                maxLen = max(maxLen, level[currLevel-1] + count);
            } else {
                // + 1 means '/'
                level[currLevel] = level[currLevel-1] + count + 1;
            }
            // reset
            count = 0; isFile = false; currLevel = 1;
        }
        return maxLen;
    }
};