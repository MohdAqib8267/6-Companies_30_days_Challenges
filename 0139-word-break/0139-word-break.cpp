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
    bool solveTab(string s, vector<string>& wordDict){
        set<string>st(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(st.find(s.substr(j,i-j+1))!=st.end()){
                    if(dp[i+1]){
                        dp[j]=true;
                        // i=j;
                        // break;
                    }
                }
            }
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // set<string>st(wordDict.begin(),wordDict.end());
        // vector<int>dp(s.size()+1,-1);
        // return solve(0,s,st,dp);
        
        return solveTab(s,wordDict);
    }
};