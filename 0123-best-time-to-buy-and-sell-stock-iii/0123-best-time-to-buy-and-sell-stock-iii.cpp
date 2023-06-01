class Solution {
public:
   int maxProfit(vector<int>& prices) {
       int min_price1=INT_MAX;
        int profit1=0;
          int min_price2=INT_MAX;
        int profit2=0;
        for(int i=0;i<prices.size();i++){
            min_price1=min(min_price1,prices[i]);
            profit1=max(profit1,prices[i]-min_price1);
            min_price2=min(min_price2,prices[i]-profit1);
            profit2=max(profit2,prices[i]-min_price2);
        }
        return profit2;
    }
    //-------------------------------------------------------------------->
    //DP
    
     // if state == true => we have to buy the stock
    
    // if state == false => we have to sell the stock
    
    // initially we have to state = true, b/c we have to buy the stock first
    
    // declare a dp
    
//     int dp[100000][3][2];
    
//     int helper(vector<int>& prices, int i, int n, int k, bool state)
//     {
//         // base case
        
//         if(k < 0 || i == n)
//             return 0;
        
//         // if already calculated
        
//         if(dp[i][k][state] != -1)
//             return dp[i][k][state];
        
//         // we have two option either include or exclude
        
//         int maxi = INT_MIN;
        
//         // inclusion part
        
//         // we will be including or excluding depends on state
        
//         if(state)
//         {
//             maxi = max(maxi, - prices[i] + helper(prices, i + 1, n, k - 1, !state));
//         }
//         else
//         {
//             maxi = max(maxi, prices[i] + helper(prices, i + 1, n, k, !state));
//         }
        
//         // exclusion part
        
//         maxi = max(maxi, helper(prices, i + 1, n, k, state));
        
//         // store the res then return
        
//         return dp[i][k][state] = maxi;
//     }
    
//     int maxProfit(vector<int>& prices) {
        
//         int n = prices.size();
        
//         // initialize dp with -1
        
//         memset(dp, -1, sizeof(dp));
        
//         // call helper
        
//         return helper(prices, 0, n, 2, true);
//     }
};