class Solution {
public:
    void solve(int st,int en,vector<int>&temp,vector<vector<int>>&ans,vector<int>adj[]){
         temp.push_back(st);
            if(st==en){
                ans.push_back(temp);
                return;
            }
        for(auto it:adj[st]){
            solve(it,en,temp,ans,adj);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        //|0-->1,2
        //|1-->3
        //|2-->3
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n-1,temp,ans,adj);
        return ans;
    }
};