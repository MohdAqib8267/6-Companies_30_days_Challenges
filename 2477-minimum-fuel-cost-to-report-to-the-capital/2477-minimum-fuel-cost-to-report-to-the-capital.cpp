class Solution {
public:
    long long ans=0;
  int dfs(const vector<vector<int>>& graph, int u,vector<bool>&vis, int seats, long long& ans) {
    int people = 1;
      vis[u]=true;
    for (auto v : graph[u]) {
        if(!vis[v])
            people += dfs(graph, v, vis, seats, ans);
    }
    if (u != 0)
    {
        // No of cars needed = ceil(people / seats)
        // no of cars = no of petrol as each car will take 1L petrol to reach next node
        ans += (people) / seats;
        if(people % seats)  
            ans++;
    }
    return people;
  }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
         //adjacency list creation
    vector<vector<int>> graph(roads.size() + 1);
    for (auto road : roads) {
        graph[road[0]].push_back(road[1]);
        graph[road[1]].push_back(road[0]);
    }
        
        vector<bool>vis(roads.size()+1,false);
        dfs(graph, 0, vis, seats, ans);
        return ans;
    }
};