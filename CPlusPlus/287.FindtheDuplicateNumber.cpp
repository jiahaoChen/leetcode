/* like a loop cycle, first loop find the loop cycle entry, 
t = X + nY + k 
2t = X + mY + k
X + k = (m-2n)Y
*/ 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n >= 1) {
            int fast = nums[nums[0]];
            int slow = nums[0];
            while (fast != slow) {
                fast = nums[nums[fast]];
                slow = nums[slow];
            }
            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};