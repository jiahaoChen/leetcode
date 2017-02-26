class Solution {
public:
    bool isHappy(int n) {
        set<int> hit;
        while(1)
        {
            int sum = 0;
            while (n)
            {
                int num = n % 10;
                sum += (num * num);
                n = n / 10;
            }
            n = sum;
            if (!(n / 10))
            {
                if (n == 1)
                {
                    return true;
                }
                else
                {
                    if (hit.find(n) != hit.end())
                        return false;
                    hit.insert(n);
                }
            }
        }
    }
};