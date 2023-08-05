class Solution {
public:
    int solve(int i,vector<int>&coins,vector<vector<int>>&dp,int amount){
        if(i<=0 or amount<0){
            return 100000;
        }
        if(amount==0) return 0;
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=100000;
        if(amount>=coins[i-1]){
            take=1+solve(i,coins,dp,amount-coins[i-1]);
        }
       int notTake=solve(i-1,coins,dp,amount);
        return dp[i][amount]=min(take,notTake);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= solve(n,coins,dp,amount);
        return ans==100000?-1:ans;
    }
};