class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,int m,int n){
     if(i==m-1 and j==n-1) return 1; 
        
        if(i>=m or j>=n){
            return 0;
        }
        
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j]=solve(i+1,j,dp,m,n)+solve(i,j+1,dp,m,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,dp,m,n);
    }
};