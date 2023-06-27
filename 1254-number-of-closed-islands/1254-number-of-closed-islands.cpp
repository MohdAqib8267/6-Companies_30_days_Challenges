class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int m,int n,bool &flag){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!=0){
            return;
        }
        if(i==0 || i==m-1 || j==0 || j==n-1){
            flag=false;
            return;
        }
        grid[i][j]=2;
        dfs(i-1,j,grid,m,n,flag);
        dfs(i,j-1,grid,m,n,flag);
        dfs(i+1,j,grid,m,n,flag);
        dfs(i,j+1,grid,m,n,flag);
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    bool flag=true;
                    dfs(i,j,grid,m,n,flag);
                    if(flag){
                        cnt++;
                    }  
                }
            }
        }
        return cnt;
    }
};