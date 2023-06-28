class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //DFS
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==(n*n)){
            return -1;
        }
        int ans=0;
         vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p=q.front();
                int r=p.first;
                int c=p.second;
                q.pop();
                for(int j=0;j<4;j++){
                    int r1=r+dir[j].first;
                    int c1=c+dir[j].second;
                    if(r1>=0 and c1>=0 and r1<n and c1<n and grid[r1][c1]==0){
                        q.push({r1,c1});
                        grid[r1][c1]=1;
                    }
                }
            }
            ans++;
        }
        return ans-1;
    }
};