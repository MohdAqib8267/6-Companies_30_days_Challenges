class Solution {
public:
    void dfs(int src,vector<vector<int>>& stones,vector<int>&vis,int n){
        vis[src]=true;
        for(int i=0;i<n;i++){
            if(!vis[i] and (stones[src][0]==stones[i][0] || stones[src][1]==stones[i][1])){
                dfs(i,stones,vis,n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
           if(!vis[i]){
               dfs(i,stones,vis,n);
               cnt++;
           }
        }
        return n-cnt;
    }
};