class Solution {
public:
    void DFS(int src,vector<int>adj[],vector<int>& vis){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();//nodes
        //connectd hone k liye m-1 branches  to honiii hi chahiye
        if(n-1>m){
            return -1;
        }
        vector<int>adj[n];
        for(int i=0;i<m;i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i,adj,vis);
                cnt++;
            }
        }
        return cnt-1;
    }
};