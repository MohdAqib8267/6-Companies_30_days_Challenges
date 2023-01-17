class Solution {
public:
    int solve(int i,int j,int n,string &s,string &str,vector<vector<int>>& dp){
        if(i>=n or j>=n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==str[j]){
            return dp[i][j]=1+solve(i+1,j+1,n,s,str,dp);
        }
        return dp[i][j]=max(solve(i+1,j,n,s,str,dp),solve(i,j+1,n,s,str,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string str=s;
         reverse(str.begin(),str.end());
        return solve(0,0,n,s,str,dp);
    }
};