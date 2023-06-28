class Solution {
public:
    void DFS(int src,vector<vector<int>>& stones,vector<int>& vis,int n){
        vis[src]=1;
        for(int i=0;i<n;i++){
            if(!vis[i] and (stones[src][0]==stones[i][0] || stones[src][1]==stones[i][1])){
                DFS(i,stones,vis,n);
            }
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        //find, connected components
        //so given conditions se connected wale component find krenege
        //ab remove kr payenge (n-cnt)
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                DFS(i,stones,vis,n);
                cnt++;
            }
        }
        // to jo ek connected component hoga wo apne neighbor ko sbko remove kar payega
        //sirf ek element backeyga component me baki sab remove me count honge
        
        // to short me her component me ek element backeyga
        // to total elements me se bss us 1 bachey hue ko minus kar do, remove wale aa jayenge
        return n-cnt; // man lo cnt 1 hi bacha
    }
};