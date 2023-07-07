class Solution {
public:
     int solve(string s, int index, vector<int>&dp){
        if(index >= s.size()) return 1;
        // if(index>s.size()) return 0;
        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];
        char ch = s[index];
        int two = 0, one = 0;
        if((ch == '1' && index+1<s.size()) || (ch == '2' && index+1<s.size() && s[index+1] <'7')) two = solve(s, index+2,dp);
        one = solve(s, index+1,dp);

        return dp[index] =  two + one;

    }

    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        if(s[0] == '0') return 0;
        return solve(s, 0, dp);
    }
};