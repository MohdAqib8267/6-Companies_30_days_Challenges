class Solution {
public:
    
   int dfs(int i,int j,int m,int n,vector<vector<int>> & grid){
       if(i<0 or i>=m or j<0 or j>=n){
           return -1; //boundary
       }
       if(grid[i][j]==0 || grid[i][j]==2){
           return 0;
       }
       grid[i][j]=2;
       int up=dfs(i-1,j,m,n,grid);
       int left=dfs(i,j-1,m,n,grid);
       int down=dfs(i+1,j,m,n,grid);
       int right=dfs(i,j+1,m,n,grid);
       if(up==-1 or left ==-1 or down==-1 or right==-1){
           return -1;
       }
       return 1+up+down+left+right;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                   int temp=dfs(i,j,m,n,grid);
                    if(temp != -1){
                        count=count+temp;
                    }
                }
                
            }
        }
        return count;
    }
};