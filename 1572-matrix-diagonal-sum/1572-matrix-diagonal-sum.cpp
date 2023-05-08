class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j or i==n-j-1)
                sum=sum+mat[i][j];  
            }
        }
      
        
        return sum;
    }
};