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
        int count=0;
        int dirx[8]={-1,-1,0,1,1,1,0,-1};
        int diry[8]={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            count++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p=q.front();
                q.pop();
                r=p.first;
                c=p.second;
                if(r==m-1 and c==n-1){
                    return count;
                }
                //traverse all 8 directions
                for(int i=0;i<8;i++){
                    if(r+dirx[i]<m and r+dirx[i]>=0 and c+diry[i]<n and c+diry[i]>=0 and grid[r+dirx[i]][c+diry[i]]==0){
                        q.push({r+dirx[i], c+diry[i]});
                        grid[r+dirx[i]][c+diry[i]]=1;
                    }
                }
                
            }
        }
        return -1;
    }
};