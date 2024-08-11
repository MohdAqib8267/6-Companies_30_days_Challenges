class Solution {
public:
    int good_nodes=0;
    int solve(int src,unordered_map<int,vector<int>>&adj,vector<int>&vis){
        vis[src]=1;
       
        int currSize=-1;
        bool isGood=true;
        int total_nodes=1;
        for(auto it:adj[src]){
            if(vis[it]!=1){
                int size=solve(it,adj,vis);
                if(currSize == -1){
                    currSize = size;
                }
                else if(currSize != size){
                    isGood=false;
                }
                total_nodes += size;
            }
        }
        if(isGood){
            good_nodes++;
        }
        return total_nodes;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(adj.size(),0);
        solve(0,adj,vis);
        return good_nodes;
    }
};