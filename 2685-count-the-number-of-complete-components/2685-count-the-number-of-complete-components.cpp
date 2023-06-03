class Solution {
public:
    pair<int,int> DFS(int i,vector<int>adj[],vector<bool>&vis){
        vis[i]=true;
        int vertex=1;
        int edgesNumber=adj[i].size();
        for(auto it:adj[i]){
            if(!vis[it]){
                pair<int,int>temp=DFS(it,adj,vis);
                vertex+=temp.first;
                edgesNumber+=temp.second;
            }
        }
        return {vertex,edgesNumber};
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                pair<int,int>temp=DFS(i,adj,vis);
                int vertex=temp.first;
                int totaledges=temp.second; //both sode edges
                if(vertex*(vertex-1)==totaledges){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};