//  For better and easier reasoning, here is the thinking thread.
// Suppose i is the current line, then:
// reference 335.SelfCrossing.png
// i and i-3 can cross
// i and i-4 can cross
// i and i-5 can cross
// no more or no less just exactly the right combination.

// Now it's time for us to restrict the conditions to make them just happen.

// i and i-3

// i>=i-2 && i-1<=i-3
// i and i-4

// i+i-4>=i-2 && i-1==i-3
// i and i-5

// i+i-4>=i-2 && i-2>=i-4 && i-1+i-5>=i-3 && i-1<=i-3


class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); ++i)
        {
            if (x[i] >= x[i-2] && x[i-1]<=x[i-3]) return true;
            if (i>3 && x[i-1] == x[i-3] && x[i-2] == x[i] + x[i-4]) return true;
            if (i>4 && x[i-1]+x[i-5] >= x[i-3] && x[i-1]<=x[i-3] && x[i]+x[i-4]>=x[i-2] && x[i-4]<= x[i-2]) return true;
            
        }
        return false;
    }
};