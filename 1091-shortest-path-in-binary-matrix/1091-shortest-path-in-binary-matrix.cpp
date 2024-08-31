class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int r,c;
        if(grid[0][0]==1){
            return -1;
        }
        if(grid[m-1][n-1]==1){
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        int count=1;
        int dirx[8]={-1,-1,0,1,1,1,0,-1};
        int diry[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p = q.front(); q.pop();
                int r=p.first, c=p.second;
                if(r==m-1 and c==n-1){
                    return count;
                }
                for(int k=0;k<8;k++){
                    int nr=r+dirx[k];
                    int nc=c+diry[k];
                    if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc]==0){
                        grid[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            count++;
        }
        return -1;
    }
};