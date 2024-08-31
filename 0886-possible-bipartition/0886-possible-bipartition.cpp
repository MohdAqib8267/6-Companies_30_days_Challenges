class Solution {
public:
    void dfs(int src,vector<int>adj[],vector<bool>&vis,vector<int>&col,bool &flag,int curr){
        if(vis[src]) return;
        vis[src]=true;
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
        vector<bool>vis(n+1,false);
        vector<int>col(n+1,-1);
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,col,flag,0);
            }
        }
        return flag;
    }
};