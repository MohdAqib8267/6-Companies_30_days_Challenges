class Solution {
public:
    bool isCycle(int src,vector<int>&stack,vector<int>&vis,vector<int>adj[]){
        vis[src]=true;
        stack[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                if(isCycle(it,stack,vis,adj)){
                    return true;
                }
            }
            else if(stack[it]){
                return true;
            }
        }
        stack[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int v=numCourses;
        vector<int>adj[v];
        for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        vector<int>stack(v,0);
        vector<int>vis(v,0);
        for(int i=0;i<v;i++){
            if(isCycle(i,stack,vis,adj)){
                return false;
            }
        }
        return true;
    }
};