class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
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
        int count=solve(i+1,s,n,dp);
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                count++;
            }
        }
        return dp[i]=count;
    }
    int countSubstrings(string s) {
        int n=s.size();
        // vector<int>dp(n+1,-1);
        // return solve(0,s,n,dp);
        
        //Tabulation
        vector<int>dp(n,1);
        for(int i=n-2;i>=0;i--){
            int count=0;
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    count++;
                }
            }
            dp[i]=dp[i+1]+count;
        }
        return dp[0];
    }
};