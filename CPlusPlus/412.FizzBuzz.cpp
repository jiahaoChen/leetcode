class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ret(n);
        for (int i = 1; i <= n; ++i) {
            bool silent = false;

            if (!(i % 3)) {
                silent = true;
                ret[i-1] += "Fizz";
            }
            if (!(i % 5)) {
                silent = true;
                ret[i-1] += "Buzz";
            }
            if (!silent)
                ret[i-1] = to_string(i);
        }
        return ret;
    }
};