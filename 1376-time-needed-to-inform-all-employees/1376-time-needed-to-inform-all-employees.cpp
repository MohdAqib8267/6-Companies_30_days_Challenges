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
       // vector<int>adj[n];
       //  for(int i=0;i<n;i++){
       //      if(manager[i]!=-1)
       //      adj[manager[i]].push_back(i);
       //  }
       //  return dfs(headID,adj,manager,informTime,n);
        
        
        //2 BFS
        
        int src = headID;
        // make a adj list 

        vector<int> adj[n];
        for(int i = 0;i<n;i++){
            int temp = manager[i];
            if(temp != -1){
                adj[temp].push_back(i);
            }
        }
        vector<int> vis(n,0);
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        int ans = 0;
        vector<int> tt(n,0);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0;i<sz;i++){
                int temp = q.front();
                q.pop();
                
                for(auto it:adj[temp]){
                    if(vis[it] == 0){
                        q.push(it);
                        tt[it] = tt[temp] + informTime[temp];
                        ans = max(ans,tt[it]);
                        vis[it] = 1;

                    }
                }                
            }

        }
       
        
        return ans;

    }
    
};