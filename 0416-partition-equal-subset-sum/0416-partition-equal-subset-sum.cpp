class Solution {
public:
    bool solve(int i,int target,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(i>=nums.size()){
            return false;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        if(sum==target) return true;
        int take=solve(i+1,target,sum+nums[i],nums,dp);
        int notTake=solve(i+1,target,sum,nums,dp);
        return dp[i][sum] = (take or notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
       
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if(sum%2 !=0 ) return false;
        int target = sum/2;
         vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return solve(0,target,0,nums,dp);
    }
};