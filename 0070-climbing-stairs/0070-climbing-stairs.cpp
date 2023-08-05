class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0 or n==1 or n==2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    }
    //space optimisation
    int solveOptimise(int n){
        if(n==0 || n==1){
            return 1;
        }
        int oneback=1;
        int twoback=1;
        for(int i=2;i<=n;i++){
            int curr=oneback+twoback;
            twoback=oneback;
            oneback=curr;
        }
        return oneback;
    }
    int climbStairs(int n) {
        // vector<int>dp(n+1,-1);
        // return solve(n,dp);
        
        //Tabulation
        // vector<int>dp(n+1,0);
        // dp[0]=1;
        // dp[1]=1;
        // for(int i=2;i<=n;i++){
        //     dp[i]=dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        
        //optimise
        return solveOptimise(n);
    }
};