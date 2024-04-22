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
        
        //DFS
        // vector<int>vis(numCourses,0);
        // vector<int>stack(numCourses,0);
        // for(int i=0;i<numCourses;i++){
        //     if(isCycle(i,adj,vis,stack)){
        //         return false;
        //     }
        // }
        // return true;
        
          // BFS 0-->1-->2  [[1,0],[2,1]]  0-->1
                  // |   |                  // 1-->2  2-->3 3-->4 4-->1
                  // 4<-- 3
        vector<int>indeg(numCourses,0);
        queue<int>q;
       for(int i=0;i<numCourses;i++){
           for(auto x:adj[i]){
               indeg[x]++;
           }
       }
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]){
               indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
       if(cnt==numCourses){
           return true;
       }
        return false;
    }
};