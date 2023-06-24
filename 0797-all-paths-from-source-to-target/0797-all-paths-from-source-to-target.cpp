class Solution {
public:
    void DFS(int src,int n,vector<int>temp,vector<vector<int>>& ans,vector<int>adj[]){
        temp.push_back(src);
        if(src==n-1){
            ans.push_back(temp);
            return;
        }
        for(auto it:adj[src]){
            DFS(it,n,temp,ans,adj);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int>temp;
        DFS(0,n,temp,ans,adj);
        return ans;
    }
};