class Solution {
public:
       int stock(vector<int>& prices,int idx,bool check,vector<vector<int>>& dp,int fee){
        if(idx==prices.size()){
            return 0;
        }
        
        if(dp[idx][check]!=-1){
            return dp[idx][check];
        }
        int profit=0;
        if(check){
            
            int not_buy=stock(prices,idx+1,check,dp,fee);
            int buy=-prices[idx]+stock(prices,idx+1,!check,dp,fee);
            profit=max(buy,not_buy);
        }
        else{
            
            int sell=prices[idx]-fee+stock(prices,idx+1,!check,dp,fee);
            int not_sell=stock(prices,idx+1,check,dp,fee);
            profit=max(sell,not_sell);
        }
        return dp[idx][check]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return stock(prices,0,true,dp,fee);
    }
};