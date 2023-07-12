class Solution {
public:
   // int maxProfit(vector<int>& prices) {
   //     int min_price1=INT_MAX;
   //      int profit1=0;
   //       int min_price2=INT_MAX;
   //      int profit2=0;
   //      for(int i=0;i<prices.size();i++){
   //          min_price1=min(min_price1,prices[i]);
   //          profit1=max(profit1,prices[i]-min_price1);
   //          min_price2=min(min_price2,prices[i]-profit1);
   //          profit2=max(profit2,prices[i]-min_price2);
   //      }
   //      return profit2;
   //  }
    //-------------------------------------------------------------------->
    //DP
    
     // if state == true => we have to buy the stock
    
    // if state == false => we have to sell the stock
    
    // initially we have to state = true, b/c we have to buy the stock first
    
    // declare a dp
    int dp[100000][3][2];
int solve(int i,int k,bool state,vector<int>& prices,int n){
    if(i>=n || k<0){
        return 0;
    }
    if(dp[i][k][state]!=-1){
        return dp[i][k][state];
    }
    
    int take=0, not_take=0;
    if(state){
        take=-prices[i]+solve(i+1,k-1,!state,prices,n);
    }
    else{
        take=prices[i]+solve(i+1,k,!state,prices,n);
    }
    not_take=solve(i+1,k,state,prices,n);
    return dp[i][k][state]=max(take,not_take);
}
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        
        // initialize dp with -1
        
         memset(dp,-1,sizeof(dp));
            return solve(0,2,true,prices,n);
    }
};