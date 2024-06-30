class Solution {
public:
    int solve(int i,int j,string &s1,string &s2,int n1,int n2,vector<vector<int>>&dp){
        if(i>=n1 || j>=n2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            return dp[i][j] = 1+solve(i+1,j+1,s1,s2,n1,n2,dp);
        }
        int c2=solve(i+1,j,s1,s2,n1,n2,dp);
        int c3=solve(i,j+1,s1,s2,n1,n2,dp);
        return dp[i][j]=max(c2,c3);
    }
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,s1,s2,n1,n2,dp);
    }
};