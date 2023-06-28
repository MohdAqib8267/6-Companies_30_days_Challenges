class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        //Dijekstra
        //set ya min heap same kaam krenge
       vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
    priority_queue<pair<int,double>,vector<pair<int,double>>,greater<pair<int,double>>>pq;
        vector<double>dist(n,0);
        dist[start]=1;
        pq.push({start,1});
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int curr_node=p.first;
            double curr_wt=p.second;
            for(auto it:adj[curr_node]){
                int next_node=it.first;
                double next_wt=it.second;
                if(dist[next_node]<dist[curr_node]*next_wt){
                    dist[next_node]=dist[curr_node]*next_wt;
                    pq.push({next_node,dist[next_node]});
                }
            }
        }
        return dist[end];
    }
};