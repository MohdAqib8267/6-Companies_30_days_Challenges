class Solution {
public:
   
    bool isPalindrome(int i,int j,string s){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
    int solve(int i,string s,vector<int>&dp){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int cnt=solve(i+1,s,dp);
        for(int j=i;j<s.size();j++){
            if(isPalindrome(i,j,s)){
                cnt++;
            }
        }
        return dp[i]=cnt;
    }
    int countSubstrings(string s) {
        // vector<int>dp(s.size()+1,-1);
       // return solve(0,s,dp);
        
        //Tabulation
        //aaa   
        vector<int>dp(s.size()+1,0);
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(int j=i;j<s.size();j++){
                if(isPalindrome(i,j,s)){
                    cnt++;
                }
            }
            dp[i]=cnt;
        }
        int sum=0;
        for(int i=0;i<dp.size();i++){
            sum+=dp[i];
        }
        return sum;
    }
};