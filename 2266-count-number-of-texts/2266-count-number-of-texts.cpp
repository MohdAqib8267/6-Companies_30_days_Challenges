class Solution {
public:
    int mod=1000000007;
    int count(string &ss,int s,vector<int>&dp)
    {
        if(s>=ss.length())
        {
            return 1;
        }
        if(dp[s]!=-1)
            return dp[s];
        int ans=0;
        char ch=ss[s];
        
        int j=s;
        int maxFreq = (ss[s]=='7' || ss[s]=='9')?4:3;
        while(j<ss.length() and j-s<maxFreq and ss[j]==ss[s])
        {
            ans=(ans%mod+count(ss,j+1,dp)%mod)%mod;
            j++;
        }
        dp[s]=ans;
        return ans;
    }
    int countTexts(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
       
        
        return count(s,0,dp);  // Memoization gives TLE
        
        
    }
};