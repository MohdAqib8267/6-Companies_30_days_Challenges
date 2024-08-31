class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int minutes=0;
        int dirX[4]={-1,0,1,0};
        int dirY[4]={0,-1,0,1};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p = q.front();
                q.pop();
                int r=p.first, c=p.second;
                for(int k=0;k<4;k++){
                    int nr=r+dirX[k];
                    int nc=c+dirY[k];
                    if(nr>=0 and nr<n and nc>=0 and nc<m and grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            minutes++;
        }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(minutes==0) return 0;
        return minutes-1;
    }
};