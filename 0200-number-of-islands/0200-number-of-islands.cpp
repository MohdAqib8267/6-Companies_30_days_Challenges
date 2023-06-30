class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid,int m,int n){
        grid[i][j]='0';
         queue<pair<int,int>>q;
       int dirx[4]={-1,0,1,0};
        int diry[4]={0,-1,0,1};
             q.push({i,j});
            while(!q.empty()){
                        int sz=q.size();
                        for(int z=0;z<sz;z++){
                            auto p=q.front(); q.pop();
                            int r=p.first, c=p.second;
                            
                            for(int k=0;k<4;k++){
                                int nr=r+dirx[k];
                                int nc=c+diry[k];
                                if(nr<m and nc<n and nr>=0 and nc>=0 and grid[nr][nc]=='1'){
                                    grid[nr][nc]='0';
                                    q.push({nr,nc});
                                }
                            }
                        }
                        
                    }
    }
    int numIslands(vector<vector<char>>& grid) {
        //using BFS
        
        int m=grid.size();
        int n=grid[0].size();
     
        int island=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                   
                   island++;
                    bfs(i,j,grid,m,n);
                }
            }
        }
        return island;
    }
};