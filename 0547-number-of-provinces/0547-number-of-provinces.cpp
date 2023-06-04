class Solution {
public:
   void dfs(vector<vector<int>>&adj , int src , vector<int>&visited)
{
    visited[src] =1 ;
    for(auto v:adj[src])
    {
        if(!visited[v])
        dfs(adj , v , visited) ;
    }
}
    int findCircleNum(vector<vector<int>>& components) {
        int n = components.size() ;
        vector<vector<int>>adj(n) ;
        for(int i= 0 ; i <components.size(); i++)
        {
            {
                for(int j =0 ; j<components[i].size(); j++)
                {
                    if(components[i][j])
                    {
                        adj[i].push_back(j) ;
                        adj[j].push_back(i);
                    }
                }
            }
        }
        vector<int>visited(n,0) ;
        int ans = 0 ;
        for(int i = 0  ; i<components.size() ; i++)
        {
            if(!visited[i])
            {
                dfs(adj , i , visited) ;
                ans++ ;
            }
        }
         return ans ;
    }
};