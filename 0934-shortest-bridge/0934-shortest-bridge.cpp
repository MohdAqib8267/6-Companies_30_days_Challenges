class Solution {
public:
    queue<pair<pair<int,int>,int>>q;
    //DFS
    void DFS(int i,int j,vector<vector<int>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid.size() || grid[i][j]==0 || grid[i][j]==2){
            return;
        }
        grid[i][j]=2;
        q.push({{i,j},0});
        DFS(i-1,j,grid);
        DFS(i,j+1,grid);
        DFS(i+1,j,grid);
        DFS(i,j-1,grid);
    }
    //BFS
    int BFS(vector<vector<int>>& grid){
       
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();
            vector<int> dx = {1, -1, 0, 0};
            vector<int> dy = {0, 0, -1, 1};
            for(int t=0;t<4;t++) {
                int ni = i+dx[t];
                int nj = j+dy[t];
                if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid.size() || grid[ni][nj] == 2)
                    continue;
                if(grid[ni][nj] == 1)
                    return d;
                grid[ni][nj] = 2;
                q.push({{ni, nj}, d+1});
            }
        }
        return -1;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    DFS(i,j,grid);
                    return BFS(grid);
                   
                } 
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<grid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return -1;
    }
};