class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mn = m+n;
        for (int i = mn-1, j = m-1, k = n-1; i >= 0; --i)
        {
            int a = j>=0?nums1[j]:INT_MIN;
            int b = k>=0?nums2[k]:INT_MIN;
            if (a >= b) {
                nums1[i] = a;
                j--;
            }
            else {
                nums1[i] = b;
                k--;
            }
        }
    }
};