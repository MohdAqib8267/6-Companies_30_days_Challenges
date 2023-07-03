class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Dijekstra
         vector<vector<int>> adj[n];
        for(auto &it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
       queue<vector<int>> q;                       //  {node,dist,stop}
        q.push({src,0,0});                          // {node,dist,stop}
        vector<int> dis(n,INT_MAX);                
        dis[src]=0;  
        while(!q.empty()){
            int node = q.front()[0];
            int cost = q.front()[1];
            int stop = q.front()[2];
            q.pop();
            
            if(stop>k) continue;                     
            
            for(auto&it : adj[node])
            {
                int nexNode = it[0];                 // nextNode
                int nexWeight = it[1];               // nextNode Weight
                
                if(cost +  nexWeight < dis[nexNode])
                {
                    dis[nexNode] = cost + nexWeight;                     
                    q.push({nexNode, dis[nexNode],stop+1});
                }
            }
        }
         if(dis[dst]==INT_MAX) return -1;                // if I didn't reached to my dst then return -1
        else return dis[dst];
    }
};