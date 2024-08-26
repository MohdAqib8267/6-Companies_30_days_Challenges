class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int currX=p.first, currY=p.second;
            for(int i=0;i<4;i++){
                int nx=currX+dir[i].first;
                int ny=currY+dir[i].second;
                if(nx>=0 and ny>=0 and nx<n and ny<m){
                   if(ans[nx][ny] > ans[currX][currY]+1){
                        ans[nx][ny]=ans[currX][currY]+1;
                       q.push({nx,ny});
                    } 
                } 
            }
        }
        return ans;
    }
};