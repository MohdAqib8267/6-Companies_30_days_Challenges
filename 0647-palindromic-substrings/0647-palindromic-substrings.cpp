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
        // vector<int>dp(n+1,-1);
        // return solve(0,s,n,dp);
        
        // vector<int>dp(n+1,0);
        // for(int i=n-1;i>=0;i--){
        //     int cnt=0;
        //     for(int j=i;j<n;j++){
        //         if(isPalindrome(i,j,s)){
        //             cnt++;
        //         }
        //     }
        //     dp[i]=cnt+dp[i+1];
        // }
        // return dp[0];
        
        //space
        int next=0;
        int curr;
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    cnt++;
                }
            }
             curr=cnt+next;
            next=curr;
        }
        return curr;
    }
};