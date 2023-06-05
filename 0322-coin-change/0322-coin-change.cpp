class Solution {
public:
    int solve(int i,vector<int>& coins,int amount,int n,vector<vector<int>>&dp){
        if(i>=n or amount<0) return 100000;
        if(amount==0) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        //take
        int take=100000;
        // if(amount-coins[i]>=0) //this will work but remove amount<0
        take = 1+solve(i,coins,amount-coins[i],n,dp);
        //not take
        int not_take = solve(i+1,coins,amount,n,dp);
        
        return dp[i][amount]=min(take,not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // int ans = solve(0,coins,amount,n,dp);
        // if(ans==100000){
        //     return -1;
        // }
        // return ans;

       
       vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i>=coins[j] and dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(1+dp[i-coins[j]],dp[i]);
                }
            }
        }
        return dp[amount] != INT_MAX ? dp[amount] : -1;
    }
};