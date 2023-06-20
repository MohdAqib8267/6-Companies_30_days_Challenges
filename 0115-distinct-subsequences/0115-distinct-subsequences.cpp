class Solution {
public:
 int solve(string &s,string &t,int i,int j,vector<vector<int>>& dp){
        if(j>=t.size()) return 1; //that's mean cover complete string t wali
        if(i>=s.size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            int include = solve(s,t,i+1,j+1,dp);
            int exclude = solve(s,t,i+1,j,dp);
            return dp[i][j]=(include+exclude);
        }
        else{
            //exclude
            return dp[i][j]=solve(s,t,i+1,j,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        //Memoization
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return solve(s,t,0,0,dp);
        
        //Tabulation
         vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
    
    //base case
    for(int i=0; i<=n; i++) {
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            //match
            if(s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else { //not match
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return (int)dp[n][m];
    }
};