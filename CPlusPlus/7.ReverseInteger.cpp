class Solution {
public:
    int reverse(int x) {
        bool positive = x >= 0? true:false;
        string s = positive?to_string(x):to_string(-x);
        std::reverse(s.begin(), s.end());
        try {
            return positive?stoi(s):-stoi(s);
        }
        catch (...) {
            return 0;
        }
    }
};