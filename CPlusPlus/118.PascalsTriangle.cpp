class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> retAll;
        for (int i = 0; i < numRows; ++i) {
            vector<int> ret(i+1,0);
            if (i == 0) {
                ret[0] = 1;
            }
            else {
                for (int j = 0; j < i+1; ++j) {
                    if (j == 0) {
                        ret[j] = 1;
                    } else if (j == i) {
                        ret[j] = 1;
                    }
                    else {
                        ret[j] = retAll[i-1][j-1]+retAll[i-1][j];
                    }
                }
            }
            retAll.push_back(ret);
        }
        return retAll;
    }
};