class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>adj[n];
        //Dijekstra
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        queue<vector<int>>q;
        q.push({src,0,0}); //{src,cost,stop}
        while(!q.empty()){
            auto temp=q.front();
            int node=temp[0];
            int cost=temp[1];
            int stop=temp[2];
             q.pop();
            if(stop>k){
                continue;
            }
           
            for(auto it:adj[node]){
                int nextNode=it[0];
                int nextWeight=it[1];
                
                if(dis[nextNode]>nextWeight+cost){
                    dis[nextNode]=nextWeight+cost;
                    q.push({nextNode,dis[nextNode],stop+1});
                }
            }
        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};