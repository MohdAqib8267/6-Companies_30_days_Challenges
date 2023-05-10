class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n));
        int left = 0, up = 0;
        int right = n - 1, down = n - 1;
        int count = 1;
        while (left <= right) {
            //top
            for (int j = left; j <= right; j++) {
                res[up][j] = count++;
            }
            up++;
            //right
            for (int i = up; i <= down; i++) {
                res[i][right] = count++;
            }
            right--;
            //down
            for (int j = right; j >= left; j--) {
                res[down][j] = count++;
            }
            down--;
            //left
            for (int i = down; i >= up; i--) {
                res[i][left] = count++;
            }
            left++;
        }
        return res;
    }
};