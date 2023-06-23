class Solution {
public:
    void comp(int src,vector<bool>& vis,vector<int>adj[]){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                comp(it,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                comp(i,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};