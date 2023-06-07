class Solution {
public:
    //DP[i][j] represent how many square end with right bottom corner as i,j
    // so DP[i][j] = min(left,up,left-up diagonal) +1;
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans=0;
        //iterate first column and all 1 will single 1 matrix
        for(int i=0;i<m;i++){
            dp[i][0]=matrix[i][0];
            ans=ans+dp[i][0];
        }
        //iterate first row and all 1 will single 1 matrix
        for(int j=1;j<n;j++){
            dp[0][j]=matrix[0][j];
            ans=ans+dp[0][j];
        }
        //iterate rest of the grid
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==1){
                    dp[i][j]=min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]})+1;
                    ans=ans+dp[i][j];
                }
                else{
                  dp[i][j]=0;  
                }
            }
        }
        return ans;
    }
};