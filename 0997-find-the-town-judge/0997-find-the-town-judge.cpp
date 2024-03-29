class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      
        vector<int>indeg(n+1,0);
        vector<int>outdeg(n+1,0);
        for(int i=0;i<trust.size();i++){
            int u=trust[i][0];
            int v=trust[i][1];
            outdeg[u]++;
            indeg[v]++;
        }
        for(int i=1;i<=n;i++){
            if( indeg[i]==n-1 and outdeg[i]==0){
                return i;
            }
        }
        return -1;
    }
};