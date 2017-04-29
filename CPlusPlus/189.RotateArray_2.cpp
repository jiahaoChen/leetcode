class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int count = 0;
        int start = 0;
        int curr = start;
        int tmp = 0;
        int beRotated = nums[curr];
        int n = nums.size();
        while (count < n) {
            do{
                tmp = nums[(curr+k)%n];
                nums[(curr+k)%n] = beRotated;
                beRotated = tmp;
                curr = (curr+k)%n;
                count++;
            }while (curr != start);
            curr = start+1;
            start = start+1;
            beRotated = nums[start];
        }
    }
};