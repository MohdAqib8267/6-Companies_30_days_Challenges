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
    int solve(int i,int n,string &s, vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=2000+9;
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                ans=min(ans,1+solve(j+1,n,s,dp));
            }
        }
        return dp[i]=ans;
        
    }
    int minCut(string s) {
        int n=s.size();
        // vector<int>dp(n+1,-1);
        // return solve(0,n,s,dp)-1;
        
        //Tabulation
        vector<int>dp(n+1,2000+9);
        dp[0]=0;
        // for(int i=1;i<n+1;i++){
        //     for(int j=i;j<n+1;j++){
        //         if(isPalindrome(i-1,j-1,s)){
        //             dp[j]=min(dp[j],1+dp[i-1]);
        //         }
        //     }
        // }
        
        //cddpd
        for(int i=1;i<n+1;i++){
            for(int j=1;j<=i;j++){
                if(isPalindrome(j-1,i-1,s)){
                    dp[i]=min(dp[i],1+dp[j-1]);
                }
            }
        }
        return dp[n]-1;
    }
};