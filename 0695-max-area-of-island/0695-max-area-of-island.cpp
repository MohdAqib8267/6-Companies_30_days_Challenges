class Solution {
public:
// void solve(int i,int j,int m,int n,int &area,vector<vector<int>>& grid){
//         if(i<0 || i>=m || j<0 || j>=n || grid[i][j]!=1){
//             return;
//         }
//         area++;
//         grid[i][j]=0;
        
//         solve(i-1,j,m,n,area,grid);
//         solve(i,j+1,m,n,area,grid);
//         solve(i+1,j,m,n,area,grid);
//         solve(i,j-1,m,n,area,grid);
//         return;
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         int ans=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1){
//                     int area=0;
//                     solve(i,j,m,n,area,grid);
//                     ans=max(ans,area);
//                 }
//             }
//         }
//         return ans;
//     }
     int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0) return 0;

        grid[i][j] = 0;
        return (1 + dfs(grid, i + 1, j)
        + dfs(grid, i - 1, j)
        + dfs(grid, i, j + 1)
        + dfs(grid, i, j - 1));
    }
      int maxAreaOfIsland(vector<vector<int>>& grid) {
          int maxArea=0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    maxArea = std::max(maxArea,  dfs(grid, i, j));
                }
            }
        }

        return maxArea;
    }
};