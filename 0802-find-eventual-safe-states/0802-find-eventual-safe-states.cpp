class Solution {
public:
    bool DFS(int i,vector<int>&ans,vector<int>&vis,vector<int>&stack,vector<vector<int>>& graph){
        vis[i]=1;
        stack[i]=1;
        for(auto it:graph[i]){
            if(!vis[it]){
                if(DFS(it,ans,vis,stack,graph)){
                    return true;
                }
            } 
            else if(stack[it]){
                    return true;
            }
        }
        ans[i]=1;
        stack[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //DFS
        //Cycle detection in directed graph
        //agar kisi node se nikalne wala koi b path terminal node per nhi phuch pata ye cycle form          kar leta hai to wo node safe node nhi hoga
        int n=graph.size();
        vector<int>check(n,0);
        vector<int>vis(n,0);
        vector<int>stack(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i,check,vis,stack,graph);
                    
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};