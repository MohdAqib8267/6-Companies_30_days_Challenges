class Solution {
public:
    void dfs(int i,int &cnt,vector<vector<int>>&adj,vector<int>&vis){
        vis[i]=1;
        cnt++;
        for(auto it:adj[i]){
            if(!vis[it]){
                dfs(it,cnt,adj,vis);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int x1=bombs[i][0];
            int y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=0;j<n;j++){
                if(i!=j){
                    long long x=abs(bombs[j][0]-x1);
                    long long y=abs(bombs[j][1]-y1);
                    if(x*x+y*y <= r1*r1){
                        adj[i].push_back(j);
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>vis(n,0);
            int cnt=0;
            dfs(i,cnt,adj,vis);
            ans=max(ans,cnt);
        }
        return ans;
        
    }
};