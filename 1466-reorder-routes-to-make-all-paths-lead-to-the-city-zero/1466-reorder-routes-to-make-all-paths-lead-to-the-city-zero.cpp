class Solution {
public:
    void DFS(int src,vector<pair<int,int>>adj[],vector<int>& vis,int &cnt){
        vis[src]=1;
        
        for(auto it:adj[src]){
            if(!vis[it.first]){
                cnt+=it.second;
                DFS(it.first,adj,vis,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<pair<int,int>>adj[n];
        for(auto i:connections){
            adj[i[0]].push_back({i[1],1});//outgoing
            adj[i[1]].push_back({i[0],0});//incoming
        }
        int cnt=0;
        vector<int>vis(n,0);
        DFS(0,adj,vis,cnt);
        return cnt;
    }
};