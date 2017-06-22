// myself answer, can get right answer, but is too slow
// O(n^2)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                maxWater = max(maxWater, (j-i)* min(height[i], height[j]));
            }
        }
        return maxWater;
    }
};

// check AC answer to get more quick
// O(n), the secret is start i = 0, j = height.size()-1,
// every height shorter than before is inevitable smaller.
class Solution {
public:
    int maxArea(vector<int>& height) {
        int j = height.size() - 1;
        int i = 0;
        int maxWater = 0;
        while(i < j) {
            int h = min(height[i], height[j]);
            maxWater = max(maxWater, (j-i)*h);
            while(height[i] <= h && i < j) ++i;
            while(height[j] <= h && i < j) --j;
        }
        return maxWater;
    }
};