class Solution {
public:
   bool cycle(int src, vector<bool> &vis, vector<bool> &stack, vector< int > adj[], vector<int> &ans)
		{
			vis[src] = true;
			stack[src] = true;

			for (auto x: adj[src])
			{
				if (!vis[x])
				{
					if (cycle(x, vis, stack, adj, ans))
					{
						return true;
					}
				}
				else if (stack[x])
				{
					return true;
				}
			}

			ans.push_back(src);
			stack[src] = false;

			return false;
		}
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
         int n = numCourses;
        vector<int>adj[n];
        	for (auto x: pre)
		{
			vector<int> data = x;
			int a = data[0];
			int b = data[1];
			adj[b].push_back(a);
		}
        vector<bool>vis(n,false);
        vector<bool>stack(n,false);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(i,vis,stack,adj,ans)){
                    return {};
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};