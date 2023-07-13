class Solution {
public:
    bool dfs(int u,vector<bool>& vis,vector<int>& col,vector<vector<int>>& graph,int curr){
        vis[u]=true;
        col[u]=curr;
        for(auto it: graph[u]){
            if(!vis[it]){
                if(dfs(it,vis,col,graph, curr xor 1)==false){
                    return false;
                }
            }
            else if(col[it]==curr){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
     
        int n=graph.size();
        vector<bool>vis(n,false);
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,col,graph,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};