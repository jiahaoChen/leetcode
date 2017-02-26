class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> hit;
        for(int x: nums)
        {
            if (hit.find(x) != hit.end())
                return true;
            hit.insert(x);
        }
        return false;
    }
};