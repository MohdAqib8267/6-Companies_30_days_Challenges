class Solution {
public:
  
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool flag=false;
        for(int i=0;i<m;i++){
            int low=0, high=n-1;
            if(matrix[i][0]<=target and matrix[i][n-1]>=target){
                while(low <= high){
                    int mid = low + (high - low)/2;
                    if(matrix[i][mid] == target) return true;
                    else if(matrix[i][mid] > target) high = mid - 1;
                    else low = mid + 1;
                }
              
            }
        }
        return flag;
    }
};