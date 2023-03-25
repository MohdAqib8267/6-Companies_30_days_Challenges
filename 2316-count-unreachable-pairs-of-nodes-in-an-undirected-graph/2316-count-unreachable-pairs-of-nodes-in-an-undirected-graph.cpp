class Solution {
public:
    void DFS(vector<int>adj[],int src,vector<int>& vis,int &cnt){
       
        cnt++;
        vis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it]){
                DFS(adj,it,vis,cnt);
            }
            
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
     vector<int> adj[n];
        for(auto a : edges){
            adj[a[0]].push_back(a[1]);
            adj[a[1]].push_back(a[0]);
        }
        vector<int> vis(n,0);
        long long ans=0;
        long long sum=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(adj,i,vis,c);
                ans += sum*c;
                sum +=c;
                c=0;
            }
        }
     
        return ans;
    }
};