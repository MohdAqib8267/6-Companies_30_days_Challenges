class Solution {
public:
    static bool compare(string &a,string &b){
        return a.size()<b.size();
       
    }
    bool isValid(string prevWord,string newWord){
        if(prevWord.size()==newWord.size()){
            return false;
        }
        if(prevWord.size()!=newWord.size()-1) return false; //handle 1 insert case
        int i=0,j=0;
        while(i<prevWord.size() && j<newWord.size()){
            if(prevWord[i]==newWord[j]){
                i++;
            }
            
            j++;
        }
        return i==prevWord.size() ;
    }
    int solve(int i,int prev,int n,vector<string>words,vector<vector<int>>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || isValid(words[prev],words[i])){
            take=1+solve(i+1,i,n,words,dp);
        }
        int not_take=solve(i+1,prev,n,words,dp);
        return dp[i][prev+1]=max(take,not_take);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),compare);
        
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solve(0,-1,n,words,dp);
        
        vector<int>dp(n+1,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(isValid(words[j],words[i]) && words[j].size()==words[i].size()-1){
                  dp[i]=max(dp[i],1+dp[j]);
                }
                ans=max(ans,dp[i]);

            }
        }
        return ans;
    }
};