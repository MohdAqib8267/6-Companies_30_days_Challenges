class Solution {
public:
   int dfs(int i, int j, int n, int m, vector<vector<int>>& mat, int val, vector<vector<int>> &dp)
    {
        if(i<0 || j<0 || i>=n || j>=m || mat[i][j]<=val)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int a = 1+dfs(i+1, j, n, m, mat, mat[i][j], dp);
        int b = 1+dfs(i, j+1, n, m, mat, mat[i][j], dp);
        int c = 1+dfs(i-1, j, n, m, mat, mat[i][j], dp);
        int d = 1+dfs(i, j-1, n, m, mat, mat[i][j], dp);
        return dp[i][j]=  max({a,b,c,d});
    }
    
    int longestIncreasingPath(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        int ans=1;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=max(ans, dfs(i,j,n,m,mat, INT_MIN, dp));
            }
        }
        return ans;
    }
};