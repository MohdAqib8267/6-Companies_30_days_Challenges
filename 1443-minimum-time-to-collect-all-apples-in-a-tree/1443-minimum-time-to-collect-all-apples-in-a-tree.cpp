class Solution {
public:
     int dfs(int node, int n, vector<int>adj[], vector<bool> &hasApple, vector<bool> &visited){
        visited[node]=true;
        int time=0;
        for(auto child: adj[node]){
            if(!visited[child]){
                int time_from_child=dfs(child,n,adj,hasApple,visited);
                if(time_from_child >0 || hasApple[child]){
                    time+= (time_from_child+2);
                }
            }
        }
        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        vector<bool> visited(n,false);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(0,n,adj,hasApple,visited);
    }
};