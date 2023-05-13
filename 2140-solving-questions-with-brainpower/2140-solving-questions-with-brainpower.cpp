class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();
        vector<long long>dp(n,-1);
    
        return rec(0,n,questions,dp); 
    }

    long long rec(int i , int n , vector<vector<int>>&questions, vector<long long>&dp)
    {
        if(i>=n)return 0;
        if(i==n-1){
            return dp[i]=questions[n-1][0];
        }
        if(dp[i]!=-1)
            return dp[i];
        
        long long pick=rec(i+questions[i][1]+1,n,questions,dp)+questions[i][0];
        long long not_pick=rec(i+1,n,questions,dp);
        
        return dp[i]=max(pick,not_pick);
    }
};