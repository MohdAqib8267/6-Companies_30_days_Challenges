class Solution {
public:
    void solve(int src,vector<int>adj[],vector<int>&vis){
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                solve(it,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //find connected components
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i].push_back(j);
                }
            }
        }
        //| 0-->1
        //| 1-->0
        //| 2
        //count connected components
        vector<int>vis(n,false);//
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};