class Solution {
public:
    void DFS(int src,vector<bool>& vis,vector<int>adj[]){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(it,vis,adj);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<rooms[i].size();j++)
                adj[i].push_back(rooms[i][j]);
        }
        vector<bool>vis(n,false);
        DFS(0,vis,adj);
        for(int i=0;i<n;i++){
            if(vis[i]!=true){
                return false;
            }
        }
        return true;
    }
};