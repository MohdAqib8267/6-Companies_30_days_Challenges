class Solution {
public:
   
   
    int solve(int i,int n,string s,vector<int>&dp){
        if(i>=n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=0,two=0;
        if((s[i]=='1' and i+1<n) || (s[i]=='2' and s[i+1]<='6' and i+1<n)){
            two=solve(i+2,n,s,dp);
        }
        one=solve(i+1,n,s,dp);
        return dp[i] = one+two;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,s,dp);
    }
};