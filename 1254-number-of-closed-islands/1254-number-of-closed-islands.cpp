class Solution {
public:
    void dfs(int i,int j,int m,int n,bool &flag,vector<vector<int>>& grid){
        if(i<0 or i>=m or j<0 or j>=n or grid[i][j]!=0){
            return;
        }
        if(i==0 or j==0 or i==m-1 or j==n-1){
            flag=false;
            return;
        }
       
        grid[i][j]=2;
        dfs(i+1,j,m,n,flag,grid);
        dfs(i-1,j,m,n,flag,grid);
        dfs(i,j+1,m,n,flag,grid);
        dfs(i,j-1,m,n,flag,grid);
       
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    bool flag=true;
                    dfs(i,j,m,n,flag,grid);
                    if(flag){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};