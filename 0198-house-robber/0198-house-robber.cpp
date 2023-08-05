class Solution {
public:
    int solve(int i,int n,vector<int>&nums, vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int inc=nums[i]+solve(i+2,n,nums,dp);
        int exc=solve(i+1,n,nums,dp);
        return dp[i] = max(inc,exc);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};