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
        
//         vector<vector<int>>graph[n+1];
//         vector<bool>vis(n+1,false);
        
//         // Build Graph
//         for (int i=0;i<roads.size();i++){
//             graph[roads[i][0]].push_back({roads[i][1],roads[i][2]});
//             graph[roads[i][1]].push_back({roads[i][0],roads[i][2]});
//         }
        //DFS
        // dfs(1,graph,vis);
        // return ans;
        
        
        // BFS
         vector<pair<int,int>>adj[n+1];  //esey initialise much better for 2 elements
       for(auto it:roads){
           adj[it[0]].push_back({it[1],it[2]});
           adj[it[1]].push_back({it[0],it[2]});
       } 
       queue<int>q;
       vector<int>vis(n+1,0);
       q.push(1);
       int ans=INT_MAX;
       while(!q.empty()){
           int node=q.front();
           q.pop();
           vis[node]=1;
           for(auto it:adj[node]){
               int nextnode=it.first;
               int wt=it.second;
                ans=min(ans,wt);
               if(vis[nextnode]==0){
                  
                   q.push(nextnode);
               }
           }
       }
       return ans;
    }
    
};