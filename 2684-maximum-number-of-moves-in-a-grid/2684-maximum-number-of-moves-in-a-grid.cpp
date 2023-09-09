class Solution {
public:
  int ans=0;
    
    int solve(int i,int j,int n,int m,vector<vector<int>>& grid,int pre,vector<vector<int>>&dp){
        if(i<0 || i>=n || j>=m || grid[i][j]<=pre){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=solve(i-1,j+1,n,m,grid,grid[i][j],dp);
        int b=solve(i,j+1,n,m,grid,grid[i][j],dp);
        int c=solve(i+1,j+1,n,m,grid,grid[i][j],dp);

        return dp[i][j]=1+max(max(a,b),c);
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,0,n,m,grid,INT_MIN,dp)-1);
        }
        return ans;
    }
};