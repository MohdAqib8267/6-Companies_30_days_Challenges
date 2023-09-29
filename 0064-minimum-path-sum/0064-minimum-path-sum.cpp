class Solution {
public:
    int sum=0;
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
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,m,n,grid,dp);
    }
};