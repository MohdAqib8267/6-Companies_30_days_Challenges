class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       // vector<vector<pair<int,int>>>adj(n+1);
        vector<pair<int,int>>adj[n+1];
        
        vector<int>dist(n+1,INT_MAX);
        
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        dist[k]=0;
        set<pair<int,int>>st;
        st.insert({k,dist[k]});
        
        while(!st.empty()){
            
            auto k=*st.begin();
            st.erase(k);
            
            auto curr_node=k.first;
            auto curr_wt=k.second;
            
            for(auto next_node:adj[curr_node]){
                
                int nxt_node=next_node.first,nxt_wt=next_node.second;
                
                if(dist[nxt_node]>dist[curr_node]+nxt_wt){
                    dist[nxt_node]=dist[curr_node]+nxt_wt;
                    st.insert({nxt_node,dist[nxt_node]});
                }
                
            }
            
        }
        
        int res=INT_MIN;
        for(int i=1; i<=n; ++i){
            if(i!=k and dist[i]==INT_MAX){
                return -1;
            }
            res=max(res,dist[i]);
        }
        
        return res;
        
        
    }
};