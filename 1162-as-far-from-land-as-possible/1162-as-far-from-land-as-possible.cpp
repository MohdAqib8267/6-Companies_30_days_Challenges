class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        //BFS
        
        int n=grid.size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
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
            int size=q.size();
            for(int ind=0;ind<size;ind++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int i1=i+dir[k].first;
                    int j1=j+dir[k].second;
                    if(i1>=0 && i1<n && j1>=0 && j1<n && grid[i1][j1]==0){
                        grid[i1][j1]=1;
                        q.push({i1,j1});
                    }
                }
                
            }
           ans++;
        }
        return ans-1;
    }
};