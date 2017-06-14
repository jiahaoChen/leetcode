class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (size == 0)
            return -1;
        int lo = 0;
        int hi = nums.size() - 1;


        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[mid] > nums[hi]) {
                lo = mid+1;
            } else {
                hi = mid;
            }
        }
        int pivot = lo;
        lo = 0;
        hi = size - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
			// here need to note, rotate not rerotate!!!
            int realmid = (mid + pivot) % size;

            if (nums[realmid] == target)
                return realmid;
            if (nums[realmid] < target)
                lo = mid+1;
            else
                hi = mid-1;
        }
        return -1;
    }
};