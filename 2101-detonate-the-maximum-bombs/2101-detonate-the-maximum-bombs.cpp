class Solution {
public:
    void dfs(int i,int &cnt,vector<int>adj[],vector<int>&vis){
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
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            long long x1=bombs[i][0];
             long long y1=bombs[i][1];
            long long r1=bombs[i][2];
            for(int j=0;j<n;j++){
                 long long x2=bombs[j][0];
                 long long y2=bombs[j][1];
                int r2=bombs[j][2];
                if((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) <= r1*r1){
                    adj[i].push_back(j);
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