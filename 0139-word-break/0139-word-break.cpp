class Solution {
public:
    bool solve(int i,string &s, set<string>&st,vector<int>& dp){
        if(i>=s.size()){
            return 1;
        }
        if(dp[i]!=-1) return dp[i];
        string str="";
        for(int ind=i;ind<=s.size();ind++){
            str+=s[ind];
            if(st.find(str)!=st.end()){
                if(solve(ind+1,s,st,dp)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,-1);
        return solve(0,s,st,dp);
    }
};