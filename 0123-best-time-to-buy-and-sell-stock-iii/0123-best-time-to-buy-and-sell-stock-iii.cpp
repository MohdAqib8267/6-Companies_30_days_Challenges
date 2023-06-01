class Solution {
public:
    //rivision
    int dp[100000][3][2]; //[length][k][true & false]
    
    int solve(int i,int k,bool state,int n,vector<int>& prices){
        if(i>=n || k<0){
            return 0;
        }
        if(dp[i][k][state]!=-1){
            return dp[i][k][state];
        }
        //for every index we check it that either we can include or not
        int maxi=INT_MIN;
        //include
        if(state){
            //if state is true, we can buy the stock
            maxi=max(maxi,-prices[i]+solve(i+1,k-1,!state,n,prices));
        }
        else{
            //else we can sell the stock
            maxi=max(maxi,prices[i]+solve(i+1,k,!state,n,prices));
        }
        
        //exlude 
        maxi=max(maxi,solve(i+1,k,state,n,prices));
        
        return dp[i][k][state]=maxi;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,2,true,n,prices);
    }
};