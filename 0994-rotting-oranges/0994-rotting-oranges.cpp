class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                      q.push({i,j});
                }
            }
        }
        int time=0;
        int dirx[4]={-1,0,1,0};
        int diry[4]={0,-1,0,1};
        while(!q.empty()){
            int sz=q.size();
            for(int z=0;z<sz;z++){
                auto p=q.front();
                q.pop();
                int i=p.first, j=p.second;
                for(int k=0;k<4;k++){
                    int ni=i+dirx[k];
                    int nj=j+diry[k];
                    if(ni>=0 and nj>=0 and ni<m and nj<n and grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        q.push({ni,nj});
                    }
                }
            }
            time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(time==0) return 0;
        return time-1;
    }
};