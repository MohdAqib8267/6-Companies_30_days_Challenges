class Solution {
public:
    int dp[51][51][101];
   vector<vector<int>> vis;
 bool check(vector<vector<int>>& grid, int row, int col, int hlt) {
        int m = grid.size(); int n = grid[0].size();
        if (row >= m || col >= n || row<0 || col<0 || hlt<=0 || vis[row][col]) return false;
        if (row==m-1 && col==n-1) {
            return hlt>grid[row][col];
        }
        if (dp[row][col][hlt]!=-1) return dp[row][col][hlt]==1;
        vis[row][col] = true;
        bool up = check(grid,row-1,col,hlt-grid[row][col]);
        bool dw = check(grid,row+1,col,hlt-grid[row][col]);
        bool lf = check(grid,row,col-1,hlt-grid[row][col]);
        bool rf = check(grid,row,col+1,hlt-grid[row][col]);
        vis[row][col] = false;
        bool result = up || dw || lf || rf;
        if(result){
            dp[row][col][hlt]=1;
        }
        else dp[row][col][hlt]=0;
        return result;
    }
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n=grid.size(), m=grid[0].size();
        memset(dp,-1,sizeof(dp));
        vis.resize(n, vector<int>(m));
        
        return check(grid,0,0,health);
    }
};