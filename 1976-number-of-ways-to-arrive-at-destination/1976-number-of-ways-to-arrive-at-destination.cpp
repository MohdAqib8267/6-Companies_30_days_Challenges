class Solution {
public:
    #define ll long long
       int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
          vector<pair<ll,ll>> adj[n];
       for(auto it:roads){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       }
       
       priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
       vector<ll> dist(n,LONG_MAX), ways(n,0);
       dist[0] = 0;
       ways[0] = 1;
       
       pq.push({0,0});
        
     
       while(!pq.empty()){
           ll dis = pq.top().first;
           ll u = pq.top().second;
           pq.pop();
           
           for(auto it: adj[u]){
               ll v = it.first;
               ll w = it.second;
               //this is the first time I am coming
               //with the short distance
               if(dis + w < dist[v]){
                   dist[v] = dis + w;
                   pq.push({dis + w,v});
                   ways[v] = ways[u];
               }
               else if(dis +w == dist[v]){
                   ways[v] = (ways[v] + ways[u])%MOD;
               }
           }
       }
        return (ways[n-1]);
    }
};