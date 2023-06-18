class Solution {
public:
    int mod=1e9+7;
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp,int m,int n){
       
        int up=0,down=0,left=0,right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i-1>=0 and grid[i-1][j]>grid[i][j]){
            up=solve(i-1,j,grid,dp,m,n);
        }
        if(j-1>=0 and grid[i][j-1]>grid[i][j]){
            left=solve(i,j-1,grid,dp,m,n);
        }
        if(i+1<m and grid[i+1][j]>grid[i][j]){
            down=solve(i+1,j,grid,dp,m,n);
        }
        if(j+1<n and grid[i][j+1]>grid[i][j]){
            right=solve(i,j+1,grid,dp,m,n);
        }
        return dp[i][j]=(1+up+down+left+right)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans%mod+solve(i,j,grid,dp,m,n)%mod)%mod;
            }
        }
        return ans;
    }
};