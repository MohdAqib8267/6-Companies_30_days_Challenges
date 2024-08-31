class Solution {
public:
    bool isCycle(int src,vector<bool>&vis,vector<bool>&stack,vector<int>adj[],vector<int>&ans){
        vis[src]=true;
        stack[src]=true;
        for(auto it:adj[src]){
            if(!vis[it]){
                if(isCycle(it,vis,stack,adj,ans)){
                    return true;
                }
            }else if(stack[it]){
                return true;
            }
        }
        ans.push_back(src);
        stack[src]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         int n = numCourses;
        vector<int>adj[n];
        	for (auto x: prerequisites)
		{
			vector<int> data = x;
			int a = data[0];
			int b = data[1];
			adj[b].push_back(a);
		}
        bool flag=false;
        vector<int>ans;
        vector<bool>vis(n,false),stack(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                
                if(isCycle(i,vis,stack,adj,ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};