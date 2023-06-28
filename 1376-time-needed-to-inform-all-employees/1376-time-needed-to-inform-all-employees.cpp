class Solution {
public:
    int dfs(int src,vector<int>adj[],vector<int>& manager,vector<int>& informTime,int n){
        int ans=0;
        for(auto it:adj[src]){
            ans=max(ans,dfs(it,adj,manager,informTime,n));
        }
        ans=ans+informTime[src];
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
       vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        return dfs(headID,adj,manager,informTime,n);
    }
};