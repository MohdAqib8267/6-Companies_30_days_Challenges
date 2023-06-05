class Solution {
public:
    int solve(int i,int n,vector<int>&nums,vector<int>& dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        //take
        int take = nums[i]+solve(i+2,n,nums,dp);
        //not take
        int not_take = solve(i+1,n,nums,dp);
        
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        //memoization
        // vector<int>dp(n+1,-1);
        // return solve(0,n,nums,dp);
        
        //Tabulation
        if(n==1){
            return nums[0];
        }
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[0];
        dp[2]=max(nums[0],nums[1]);
        for(int i=3;i<=n;i++){
            int take = nums[i-1]+dp[i-2];
            int not_take = dp[i-1];
            dp[i]=max(take,not_take);
        }
        return dp[n];
    }
   
};