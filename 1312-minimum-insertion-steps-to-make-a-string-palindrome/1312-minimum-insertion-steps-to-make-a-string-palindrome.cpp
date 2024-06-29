class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j]= solve(i+1,j-1,s,dp);
        }
        else{
            return dp[i][j]=1+min(solve(i+1,j,s,dp),solve(i,j-1,s,dp));
        }
    }
    int minInsertions(string s) {
        
//         Intuition
// * Check longest common subsequence between string s and it's reverse string t.
// * len(s) - lcs(s, t) will be the number of non-matching characters.
// * Hence we need to add those many characters.
        //so we can calculate n-solve(0,0,s,t) //solve give lenth of longes palindromic subsqence, but here in memo i have calculate direclty unmatched element while in tabulation calculate LPS and minus from n.
            
        int n=s.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(0,n-1,s,dp);
        
        
        //TABULATION
//        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
//     string t=s;
//         reverse(t.begin(),t.end());
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= n; j++) {
//                 if (s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
//                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }

//         return n- dp[n][n];
        
        
        //Space optimise
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == s[n-j]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return n-prev[n];
    }
};