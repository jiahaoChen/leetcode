class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (!matrix.size() || !matrix[0].size())
            return ret;
        int m = matrix.size();
        int n = matrix[0].size();
        enum direction{LEFT, RIGHT, UP, DOWN};
        int all = m*n;
        int count = 0;
        int direct = RIGHT;
        int up = 1;
        int down = m-1;
        int left = 0;
        int right = n-1;
        int i = 0;
        int j = 0;
        while (count < all) {
            // cout << matrix[i][j] << endl;
            ret.push_back(matrix[i][j]);
            count++;
            switch (direct) {
                case LEFT:
                    if (j == left) {
                        direct = UP;
                        left++;
                        i--;
                    }
                    else {
                        j--;
                    }
                break;
                case RIGHT:
                    if(j == right) {
                        direct = DOWN;
                        right--;
                        i++;
                    } else {
                        j++;
                    }
                break;
                case UP:
                    if (i == up) {
                        direct = RIGHT;
                        up++;
                        j++;
                    } else {
                        i--;
                    }
                break;
                case DOWN:
                    if (i == down) {
                        direct = LEFT;
                        down--;
                        j--;
                    } else {
                        i++;
                    }
                break;
            }
        }
        return ret;
    }
};