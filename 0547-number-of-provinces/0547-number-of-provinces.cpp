class Solution {
public:
    void DFS(int src,vector<bool>&vis,vector<int>adj[]){
        if(vis[src]) return;
        vis[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(it,vis,adj);
            }
        }
    }
    void BFS(queue<int>&q,vector<bool>&vis,vector<int>adj[]){
        while(!q.empty()){
            int src = q.front();
            q.pop();
            vis[src]=true;
            for(auto it:adj[src]){
                if(!vis[it]){
                  q.push(it);  
                }
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j && isConnected[i][j]==1){
                   adj[i].push_back(j); 
                    
                }
            }
        }
        vector<bool>vis(n,false);
        int cnt=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         DFS(i,vis,adj);
        //         cnt++;
        //     }
        // }
        
        
        //BFS
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                q.push(i);
                BFS(q,vis,adj);
                cnt++;
            }
        }
        return cnt;
    }
};