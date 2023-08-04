class Solution {
public:
    
//     void DFS(int i,int j,vector<vector<char>>& grid,int m,int n){
//         if(i<0 or i>=m or j<0 or j>=n or grid[i][j]=='0'){
//             return;
//         }
//         grid[i][j]='0';
//         DFS(i-1,j,grid,m,n);
//         DFS(i,j-1,grid,m,n);
//         DFS(i+1,j,grid,m,n);
//         DFS(i,j+1,grid,m,n);
        
//     }
    
    void bfs(int i,int j,vector<vector<char>>& grid,int m,int n){
        int dirx[4]={-1,0,1,0};
        int diry[4]={0,-1,0,1};
        grid[i][j]='0';
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p=q.front(); q.pop();
                int r=p.first, c=p.second;
                for(int s=0;s<4;s++){
                    int nr=r+dirx[s];
                    int nc=c+diry[s];
                     if(nr<m and nc<n and nr>=0 and nc>=0 and grid[nr][nc]=='1'){
                                        grid[nr][nc]='0';
                                        q.push({nr,nc});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    // DFS(i,j,grid,m,n);
                    bfs(i,j,grid,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};