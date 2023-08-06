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
    int solveTab(string s){
        int n=s.size();
        vector<int> dp(n + 1, 0);
    dp[0] = 1; // Empty string has one decoding (base case)
    
    for (int i = 1; i <= n; i++) {
        // If the current character is not '0', it can be decoded as a single digit
        if (s[i - 1] != '0') {
            dp[i] += dp[i - 1];
        }
        
        // If the current and previous characters form a valid two-digit code
        if (i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
            dp[i] += dp[i - 2];
        }
    }
    
    return dp[n];
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        if(s[0]=='0'){
            return 0;
        }
        // return solve(0,s,n,dp);
        return solveTab(s);
    }
};