class Solution {
public:
    void dfs(int src,vector<bool>& vis,vector<int>adj[]){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++){
                adj[i].push_back(rooms[i][j]);
            }
        }
        vector<bool>vis(n,false);
        dfs(0,vis,adj);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};