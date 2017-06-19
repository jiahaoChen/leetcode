class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        vector<int> mergeNum;
        int y = 0;
        int z = 0;
        for (int i = 0; i < k ; ++i) {
            if (y == nums1.size())
                mergeNum.push_back(nums2[z++]);
            else if (z == nums2.size())
                mergeNum.push_back(nums1[y++]);
            else {
                if (nums1[y] <= nums2[z])
                    mergeNum.push_back(nums1[y++]);
                else
                    mergeNum.push_back(nums2[z++]);
            }
        }
        return k % 2? mergeNum[k/2]: ((double)mergeNum[k/2]+(double)mergeNum[k/2-1])/2;
    }
};