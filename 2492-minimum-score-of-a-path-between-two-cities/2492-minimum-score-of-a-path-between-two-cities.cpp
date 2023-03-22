class Solution {
public:
     
    
    int ans=1e9;
    void dfs(int node, vector<vector<int>>graph[],vector<bool>&vis){
        vis[node]=1;
        for (auto i:graph[node]){
            ans=min(ans,i[1]);
            if (!vis[i[0]]){
                dfs(i[0],graph,vis);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        // graph.resize(n+1);
        vector<vector<int>>graph[n+1];
        vector<bool>vis(n+1,false);
        vis.resize(n+1);
        // Build Graph
        for (int i=0;i<roads.size();i++){
            graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        dfs(1,graph,vis);
        return ans;
    }
    
};