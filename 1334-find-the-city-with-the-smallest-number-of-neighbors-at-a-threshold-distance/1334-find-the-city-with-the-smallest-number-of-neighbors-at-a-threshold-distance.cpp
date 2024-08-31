class Solution {
public:
     int djk(int src,int n,vector<pair<int,int>>adj[],int distanceThreshold){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        vector<int>dis(n,1e9);
        dis[src]=0;
        q.push({0,src});
        while(!q.empty()){
            int fnode=q.top().second;
            int d=q.top().first;//wt
            q.pop();
            for(auto i:adj[fnode]){
                int node=i.first;
                int wt=i.second;
                if(dis[node]>dis[fnode]+wt){
                    dis[node]=dis[fnode]+wt;
                    q.push({dis[node],node});
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=distanceThreshold){
                ans++;
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int mini=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            int temp=djk(i,n,adj,distanceThreshold);
            if(temp<=mini){
                mini=temp;
                ans=i;
            }
        }
        return ans;

    }
};