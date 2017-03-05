class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0)
            return true;
        if (x < 0)
            return false;
        int digitCount = 1;
        int tmp = x;
        while(tmp/10)
        {
            tmp /= 10;
            digitCount *= 10;
        }
        int base = 10;
        while(digitCount >= base)
        {
            if (x/digitCount != x%base)
                return false;
            x %= digitCount;
            digitCount /= 100;
            x /= 10;
        }
        return true;
    }
};