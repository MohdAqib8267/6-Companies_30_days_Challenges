class Solution {
public:
    int solve(int i,int j,int n,string &s,vector<vector<int>>& dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
          dp[i][j]=solve(i+1,j-1,n,s,dp);
        }
        else{
            dp[i][j]=1+min(solve(i+1,j,n,s,dp),solve(i,j-1,n,s,dp));
        }
        return dp[i][j];
    }
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,n,s,dp);
        
    }
};