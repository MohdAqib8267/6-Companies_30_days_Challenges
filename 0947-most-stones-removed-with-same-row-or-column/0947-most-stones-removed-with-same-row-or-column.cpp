class Solution {
public:
    void DFS(int ind,vector<bool>& vis,int n,vector<vector<int>>& stones){
        vis[ind]=true;
        for(int i=0;i<n;i++){
            if(!vis[i] and (stones[ind][0]==stones[i][0] || stones[ind][1]==stones[i][1])){
                DFS(i,vis,n,stones);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        //basically this is connected components based question
        int n=stones.size();
        vector<bool>vis(n,false);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]){
                continue;
            }
            DFS(i,vis,n,stones);
            cnt++; //gives no of connected components
        }
        //jo connected honge let m unme m-1 nikal jayege ek reh jayega
        //so isliye (n-count)
        return n-cnt;
    }
};