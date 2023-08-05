class Solution {
public:
    int solve(int i,int j,string &s1, string &s2,int n1,int n2,vector<vector<int>>&dp){
        if(i>=n1 or j>=n2){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+solve(i+1,j+1,s1,s2,n1,n2,dp);
        }
        return dp[i][j]=max(solve(i+1,j,s1,s2,n1,n2,dp),solve(i,j+1,s1,s2,n1,n2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(0,0,text1,text2,n1,n2,dp);
    }
};