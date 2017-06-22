class Solution {
public:
    bool isHappy(int n) {
        set<int> hit;
        while (n != 1) {
            if (hit.find(n) != hit.end())
                return false;
            hit.insert(n);
            int tmp = 0;
            while (n) {
                tmp +=  pow(n%10, 2);
                n /= 10;
            }
            n = tmp;
        }
        return true;
    }
};