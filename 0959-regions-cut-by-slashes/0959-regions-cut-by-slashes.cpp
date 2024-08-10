class Solution {
public:
//     We can upscale the input grid to [n * 3][n * 3] grid and draw "lines" there. Then, we can paint empty regions using DFS and count them. Picture below says it all. Note that [n * 2][n * 2] grid does not work as "lines" are too thick to identify empty areas correctly.

// This transform this problem into 200. Number of Islands, where lines ('1') are the water, and rest ('0') is the land.

// I came up with this solution after I drew a few examples, and because I was lazy and saw it as an easy way.
    
    
    //[" /","/ "] it's 1*2 grid. (0,1)='/' and (0,2)='/'
    void dfs(int i,int j,vector<vector<int>>&g){
        if(i<0 || i>=g.size() || j<0 || j>=g[0].size() || g[i][j]==1){
            return;
        }
        g[i][j] = 1;
        dfs(i+1,j,g);
        dfs(i,j-1,g);
        dfs(i-1,j,g);
        dfs(i,j+1,g);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>>g(n*3,vector<int>(n*3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    g[i*3][j*3+2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i][j]=='\\'){
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2]=1;    
                 }
            }
        }
        int cnt=0;
        for(int i=0;i<n*3;i++){
            for(int j=0;j<n*3;j++){
                if(g[i][j] == 0){
                    dfs(i,j,g);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};