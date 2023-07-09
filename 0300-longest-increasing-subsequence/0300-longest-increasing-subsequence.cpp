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
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        return solve(0,-1,nums,dp);
    }
};