class Solution {
public:
    int solve(int st,int n,vector<int>&nums,vector<int>&dp){
        if(st>=n-1){
            return 0;
        }
        if(dp[st]!=-1){
            return dp[st];
        }
        if(nums[st]==0){
            return 10000;
        }
        int step=10000;
        for(int i=st+1;i<=min(n-1,st+nums[st]);i++){
            step=min(step,1+solve(i,n,nums,dp));
        }
        return dp[st]=step;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans=solve(0,n,nums,dp);
        
        return ans==10000?false:true;
    }
};