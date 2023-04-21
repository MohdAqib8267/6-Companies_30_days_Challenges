class Solution {
public:
   const int mod=1e9+7;
 int dp[101][101][101];
   int helper(vector<int>&group,vector<int>&profit,int n,int minProfit,int index){
        if(n==0 || index==group.size()){
            return 0;
        }
       if(dp[index][minProfit][n]!=-1) return dp[index][minProfit][n];
        int include=0;
        if(n>=group[index]){
            if(minProfit-profit[index]<=0){
                include++;
            }
            int temp = max(0,minProfit-profit[index]);
            include= (include + helper(group,profit,n-group[index],temp,index+1) )%mod;
        }
        int exclude = helper(group ,profit,n,minProfit,index+1);

        return dp[index][minProfit][n]= (include  +exclude )%mod;
   }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
          int ans= helper(group,profit,n,minProfit,0);
          if(minProfit==0){
             ans=(ans+1)%mod;
          }
         return ans;

    }
};