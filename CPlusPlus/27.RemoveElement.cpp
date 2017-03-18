class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        vector<int>::iterator it = nums.begin();
        for (vector<int>::iterator it = nums.begin(); it != nums.end();)
        {
            if (*it == val)
                it = nums.erase(it); // P.S.: vector erase return the next iterator
            else
                ++it;
        }
        return nums.size();
    }
};