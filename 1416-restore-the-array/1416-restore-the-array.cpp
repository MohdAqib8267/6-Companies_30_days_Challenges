class Solution {
public:
    int mod=1e9+7;
    int solve(int i,string &s ,int n,int k,vector<int>&dp){
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int cnt=0;
        for(int j=i;j<n;j++){
            long long num = stol(s.substr(i,j-i+1));
            
            if(num==0 || num>k){
                break;
            }
            cnt=(cnt+solve(j+1,s,n,k,dp))%mod;
        }
        return dp[i]=cnt;
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,n,k,dp);
    }
};