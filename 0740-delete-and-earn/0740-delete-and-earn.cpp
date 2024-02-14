class Solution {
public:
    int solve(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=nums[i];
        int idx=i+1;
        while(idx<n and nums[i]==nums[idx]){
            sum+=nums[i];
            idx++;
        }
        while(idx<n and nums[idx]-nums[i]==1){
            idx++;
        }
        int inc=sum+solve(idx,n,nums,dp);
        int exc=solve(i+1,n,nums,dp);
        return dp[i] = max(inc,exc);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};