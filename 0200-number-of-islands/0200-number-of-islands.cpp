class Solution {
public:
    void DFS(int i,int j,vector<vector<char>>& grid,int m,int n){
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]=='0'){
            return;
        }
        grid[i][j]='0';
        DFS(i-1,j,grid,m,n);
        DFS(i,j-1,grid,m,n);
        DFS(i+1,j,grid,m,n);
        DFS(i,j+1,grid,m,n);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    DFS(i,j,grid,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};