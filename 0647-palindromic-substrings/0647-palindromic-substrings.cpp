class Solution {
public:
    bool isPalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int solve(int i,string s,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int cnt=solve(i+1,s,n,dp);
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                cnt++; 
            }
        }
        return dp[i]=cnt;
    }
    int countSubstrings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,s,n,dp);
    }
};