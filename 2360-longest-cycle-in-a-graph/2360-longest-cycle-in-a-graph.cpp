class Solution {
public:
    void DFS(int src,vector<int>adj[],vector<int>&vis,int &cnt){
        if(vis[src]){
            return;
        }
        vis[src]=1;
        cnt++;
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(it,adj,vis,cnt);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        vector<int>indeg(n,0);
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            
             adj[i].push_back(edges[i]);
            if(edges[i]!=-1){
            //i--->edges[i]
            indeg[edges[i]]++; 
            }
           
        }
        queue<int>q;
        //push elements in queue, which have indegree zero
        for(int i=0;i<indeg.size();i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int node = q.front();
              // if(vis[node]) continue;
            vis[node] = 1;
            q.pop();
            for(auto it:adj[node]){
                if(it!=-1){
                    indeg[it]--;
                     if(indeg[it]==0){
                    q.push(it);
                }
            }   
            }
        }
        // cout<<cnt;
       //now check cycles length
//         [1,2,0,4,5,6,3,8,9,7] mutilple cycles
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int count=0;
                DFS(i,adj,vis,count);
                cout<<count;
                ans=max(ans,count);
            }
        }
        return ans==INT_MIN? -1 : ans;
        
    }
};