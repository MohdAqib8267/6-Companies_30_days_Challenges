class Solution {
public:
    int DFS(int headId,vector<int>adj[],vector<int>& informTime){
        int ans=0;
        for(auto it:adj[headId]){
            ans=max(ans,DFS(it,adj,informTime));
        }
        ans=ans+informTime[headId];
        return ans;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        
        return DFS(headID,adj,informTime);
        
    }
};