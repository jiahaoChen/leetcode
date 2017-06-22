class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (!n) return 0;

        int ret = 0;
        int maxIdx = 0;
        for (int k = 0; k < n; ++k)
            maxIdx = height[k]>height[maxIdx]?k:maxIdx;

        int i = 0;
        while (i < maxIdx) {
            int tmp = 0;
            int j = i+1;
            for (; j <= maxIdx && height[i] > height[j]; ++j) {
                tmp += (height[i] - height[j]);
            }
            if (j <= maxIdx && height[j] >= height[i])
                ret += tmp;
            i = j;
        }

        i = n-1;
        while (i > maxIdx) {
            int tmp = 0;
            int j = i-1;
            for (; j >= maxIdx && height[i] > height[j]; --j) {
                tmp += (height[i] - height[j]);
            }
            if (j >= maxIdx && height[j] >= height[i])
                ret += tmp;
            i = j;
        }

        return ret;
    }
};