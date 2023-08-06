class Solution {
public:
    int solve(int i,string s,int n,vector<int>&dp){
        if(i>=n){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int one=0;
        int two=0;
        if((s[i]=='1' and i+1<n) || (s[i]=='2' and i+1<n and s[i+1]<'7')){
            two=solve(i+2,s,n,dp);
        }
        one=solve(i+1,s,n,dp);
        return dp[i]=one+two;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        
        return solve(0,s,n,dp);
    }
};