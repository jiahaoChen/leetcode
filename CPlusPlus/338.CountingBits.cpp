class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret;
        if (num == 0)
        {
            ret.push_back(0);
            return ret;
        }
        if (num == 1)
        {
            ret.push_back(0);
            ret.push_back(1);
            return ret;
        }
        ret.push_back(0);
        ret.push_back(1);
        for (int i = 2; i/2 <= num; i*=2)
        {
            int rn = ret.size();
            for (int j = 0; j+rn <= num && j < rn; ++j)
            {
                ret.push_back(ret[j]+1);
            }
        }
        return ret;
    }
};