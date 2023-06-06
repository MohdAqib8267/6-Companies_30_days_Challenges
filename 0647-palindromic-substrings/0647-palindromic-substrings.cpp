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
    int solve(int i,int n,string &s,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int count=solve(i+1,n,s,dp);
        for(int ind=i;ind<n;ind++){
            if(isPalindrome(i,ind,s)){
                count++;
            }
        }
        return dp[i] = count;
        
    }
    int countSubstrings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,s,dp);
    }
};