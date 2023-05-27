class Solution {
public:
    int solve(int i,int j,vector<int>& piles,vector<vector<int>>& dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==j){
            return piles[i];
        }
        int l=piles[i]+min(solve(i+2,j,piles,dp),solve(i+1,j-1,piles,dp));
        int r=piles[j]+min(solve(i,j-2,piles,dp),solve(i+1,j-1,piles,dp));
        
        return dp[i][j]=max(l,r);
        
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int alice = solve(0,n-1,piles,dp);
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+piles[i];
        }
        int bob = sum-alice;
        return alice>bob;
    }
};