class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=1;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1')
                dp[i][j]=max(dp[i][j],1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]}));
                
            }
        }
          int maxx=0;
      for(int i=0;i<m;i++){
            for(int j=0;j<n;j++) maxx=max(maxx,dp[i][j]);
        }
        return maxx*maxx;
    }
};