class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(i==m-1 and j==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int b=solve(i+1,j,m,n,grid,dp);
        int r=solve(i,j+1,m,n,grid,dp);
        return dp[i][j]=grid[i][j]+min({b,r});
    }
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solve(0,0,m,n,grid,dp);
         vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                if(i==0){
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+min({dp[i-1][j],dp[i][j-1]});
            }
        }
        return dp[m-1][n-1];
    }
};