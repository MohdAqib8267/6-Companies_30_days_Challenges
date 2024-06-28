class Solution {
public:
    int solve(int i,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(i>=coins.size() || amount<0){
            return 10000;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }
        int take=10000,not_take=10000;
        if(coins[i]<=amount){
            take=1+solve(i,coins,amount-coins[i],dp);
        }
        not_take = solve(i+1,coins,amount,dp);
        return dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        // vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        // int ans=solve(0,coins,amount,dp);
        // return ans==10000?-1:ans;
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,10000 + 1));
        //base case: amount==0
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                
                if(coins[i-1]>j){
                    //not take
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    //take
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                
            }
        }
        return dp[n][amount]==10000 + 1?-1:dp[n][amount];
    }
};