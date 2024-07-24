class Solution {
public:
    int solve(int i,int n,string &s, vector<int>&dp){
        if(i==n){
            return 1;
        }
        if(s[i]=='0') return 0;
        if(dp[i] != -1) return dp[i];
        int two=0;
        if(i+1<n){
            if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6')){
                two=solve(i+2,n,s,dp);
            }
        }
        int one=solve(i+1,n,s,dp);
        return dp[i] = one+two;
    }
    int numDecodings(string s) {
        int n=s.size();
        // vector<int>dp(n+1,-1);
        // return solve(0,n,s,dp);
        
        //Tabulation
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
               int one = dp[i + 1];
                int two = 0;
                if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))) {
                    two = dp[i + 2];
                }
                dp[i] = one + two;
            }
        }
        return dp[0];
    }
};