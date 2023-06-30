class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<int>& vis,vector<int>&col,bool &flag,int curr){
        vis[src]=1;
        col[src]=curr;
        for(auto it:adj[src]){
           if(!vis[it]){
               dfs(it,adj,vis,col,flag,curr xor 1);
           }
            else if(vis[it] and col[it]==curr){
                flag=false;
                return;
            }
        }
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>col(n+1,-1);
        vector<int>vis(n+1,0);
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,col,flag,0);
            }
        }
        return flag;
    }
};