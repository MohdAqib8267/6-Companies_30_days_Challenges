class Solution {
public:
    void DFS(int i,int j,int m,int n,vector<vector<char>>&grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0' || grid[i][j]=='2'){
            return;
        }
        grid[i][j]='2';
        DFS(i,j-1,m,n,grid);
        DFS(i-1,j,m,n,grid);
        DFS(i,j+1,m,n,grid);
        DFS(i+1,j,m,n,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    DFS(i,j,m,n,grid);
                    count++;
                }
            }
        }
        return count;
    }
};