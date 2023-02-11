class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<redEdges.size();i++){
            int a=redEdges[i][0];
            int b=redEdges[i][1];
            adj[a].push_back({b,0}); //red color -- 0
        }
        for(int i=0;i<blueEdges.size();i++){
            int u=blueEdges[i][0];
            int v=blueEdges[i][1];
            adj[u].push_back({v,1}); //blur color -- 1
        }
        vector<int>ans(n,INT_MAX);
        
        ans[0]=0;
           map<pair<int,int>,int> vis;
        vis[{0,-1}]=true; //{node,col}=true
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,-1},0}); //{{node,col},distance}
        
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto p = q.front();
                q.pop();
                int u=p.first.first;//node
                int col=p.first.second;//color
                int dis=p.second;
                
                ans[u]=min(ans[u],dis);
                for(auto it:adj[u]){
                   if(it.second != col and vis[{it.first,it.second}]!=true){
                       vis[{it.first,it.second}]=true;
                       q.push({{it.first,it.second},dis+1});
                   }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==INT_MAX){
                ans[i]=-1;
            }
        }
        return ans;
    }
};