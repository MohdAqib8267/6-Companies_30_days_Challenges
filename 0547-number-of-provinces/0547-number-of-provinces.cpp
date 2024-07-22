class Solution {
public:
    void DFS(int src,vector<bool>&vis,vector<int>adj[]){
        if(vis[src]) return;
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j && isConnected[i][j]==1){
                   adj[i].push_back(j); 
                    
                }
            }
        }
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};