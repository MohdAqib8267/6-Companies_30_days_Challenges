class Solution {
public:
    int solve(int ind,int k,int n,vector<vector<int>>& piles,vector<vector<int>>&dp){
      if(ind == n || k == 0) return 0;
        if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int res = solve(ind+1,k,n,piles,dp);
        int curr=0;
        for(int j=0;j<piles[ind].size() && j<k;j++){
            curr = curr+piles[ind][j];
            res=max(res,curr+solve(ind+1,k-j-1,n,piles,dp));
        }
        return dp[ind][k]=res;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n=piles.size();
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(0,k,n,piles,dp);
    }
};