class Solution {
public:
    bool isCycle(int src,vector<int>adj[],vector<int>&vis,vector<int>&stack){
        vis[src]=true;
        stack[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                if(isCycle(it,adj,vis,stack)){
                    return true;
                }
            }else if(stack[it]){
                return true;
            }
        }
        stack[src]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
         for(int i=0;i<prerequisites.size();i++){
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            adj[b].push_back(a);
        }
        //if cycle present then we can schedule
        vector<int>vis(numCourses,0);
        vector<int>stack(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(isCycle(i,adj,vis,stack)){
                return false;
            }
        }
        return true;
    }
};