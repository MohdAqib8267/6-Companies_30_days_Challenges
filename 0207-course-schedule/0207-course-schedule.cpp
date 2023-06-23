class Solution {
public:
    bool cycle(int src,vector<int>& vis,vector<int>& stack, vector<int> adj[]){
         vis[src] = true;
        
        // mark the curr node in the rec_stack
        
        stack[src] = true;
        
        for(auto v : adj[src])
        {
            // if adjacent node is not visited
            
            if(vis[v] == false)
            {
                if(cycle( v, vis, stack, adj))
                    return true;
            }
            
            // if adjacent node is visited, and currently present int the rec_stack, then cycle found
            
            else if(stack[v]){
            
                
                    return true;
            }
        }
        
        // remove the curr node from rec_stack
        
        stack[src] = false;
        
        return false;
             
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      int V=numCourses;
        vector<int>adj[V];
        for(int i=0;i<prerequisites.size();i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];
            adj[v].push_back(u);
        }
        //if cycle is present then we can not finish all courses
        vector<int>vis(V,0);
        vector<int>stack(V,0);
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                   if(cycle(i,vis,stack,adj)){
                return false;
            }
            }
         
        }
        return true;
    }
};