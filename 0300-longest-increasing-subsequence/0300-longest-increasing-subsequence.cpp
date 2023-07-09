class Solution {
public:
    int solve(int i,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int take=0,not_take=0;
        if(prev==-1 || nums[prev]<nums[i]){
            take=1+solve(i+1,i,nums,dp);
        }
        not_take=solve(i+1,prev,nums,dp);
        return dp[i][prev+1]=max(take,not_take);
    }
    int solveTab(vector<int>& nums){
        int n=nums.size();
        vector<int>dp(n+1,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
                ans=max(ans,dp[i]);
            }
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solve(0,-1,nums,dp);
        return solveTab(nums);
    }
};