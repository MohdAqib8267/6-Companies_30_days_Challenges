class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int up=0,left=0,down=0,right=0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i-1>=0 and matrix[i-1][j]>matrix[i][j]){
            up=1+solve(i-1,j,m,n,matrix,dp);
        }
        if(j-1>=0 and matrix[i][j-1]>matrix[i][j]){
            left=1+solve(i,j-1,m,n,matrix,dp);
        }
        if(i+1<m and matrix[i+1][j]>matrix[i][j]){
            down=1+solve(i+1,j,m,n,matrix,dp);
        }
        if(j+1<n and matrix[i][j+1]>matrix[i][j]){
            right=1+solve(i,j+1,m,n,matrix,dp);
        }
        return dp[i][j]=max({up,left,down,right});
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,solve(i,j,m,n,matrix,dp));
            }
        }
        return 1+ans;
    }
};