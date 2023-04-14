class Solution {
public:
   int solve(int i,int j,string &s,int n,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == s[j] and i<j){
            dp[i][j] = 2+solve(i+1,j-1,s,n,dp);
        }
        else if(s[i]==s[j]){
            dp[i][j]=1+solve(i+1,j-1,s,n,dp);
        }
        else{
            dp[i][j] = max(solve(i+1,j,s,n,dp),solve(i,j-1,s,n,dp));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,n,dp);
    }
};