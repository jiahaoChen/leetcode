class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> cand;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) cand.erase(nums[i-k-1]);
            if (!cand.insert(nums[i]).second) { // pair::first set to an iterator pointing to either the newly  
                return true;                    // inserted element or to the equivalent element already in the set
            }                                   // pair::second element in the pair is set to true if a new element 
        }                                       // was inserted or false if an equivalent element already existed.
        return false;
    }
};