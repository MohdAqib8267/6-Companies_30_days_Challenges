class Solution {
public:
    bool solve(int i, string &s,   set<string>st, vector<int>&dp){
        if(i>=s.size()){
            return true;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        string str="";
        for(int j=i;j<s.size();j++){
            str+=s[j];
            if(st.find(str) != st.end()){
                if(solve(j+1, s, st, dp)){
                    // cout<<str<<endl;
                    return dp[i] = true;
                }
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         int n = wordDict.size();
    
        set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,-1);
    return solve(0,s,st,dp);
    
    }
};