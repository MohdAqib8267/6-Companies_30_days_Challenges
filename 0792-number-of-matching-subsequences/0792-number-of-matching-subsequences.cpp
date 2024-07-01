class Solution {
public:
    bool isMatch(int i,int j,string &s,string &word,int n,vector<vector<bool>>&dp){
        if(j>=word.size()){
            return true;
        }
        if(i>=n){
            return false;
        }
        if(dp[i][j]!=false){
            return dp[i][j];
        }
        if(s[i] == word[j]){
            return dp[i][j]=isMatch(i+1,j+1,s,word,n,dp);
        }
        else{
            return dp[i][j]=isMatch(i+1,j,s,word,n,dp);
        }
    }
    
    //without dp solution
      bool findFuntions(string &s, string t) 
    {
        int i = 0, j = 0, n = s.size(), m = t.size();
        while(j<n and i < m)
            if(s[j++]==t[i]) i++;
        return (t.size() - i) == 0;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int n=s.size();
        int cnt=0;
        
//         for(int i=0;i<words.size();i++){
//             vector<vector<bool>>dp(n+1,vector<bool>(words[i].size()+1,false));
//             if(isMatch(0,0,s,words[i],n,dp)){
//                 cnt++;
//             }
            
          
//         }
//         return cnt;
        
        map<string,int>mp;
        for(auto &str:words) mp[str]++;
        
        int ans = 0;
        for(auto ok:mp)
            if(findFuntions(s, ok.first)) ans += ok.second;
        return ans;
    }
};