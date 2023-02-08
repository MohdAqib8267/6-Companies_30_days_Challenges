class Solution {
public:
    int solve(int i,int n,vector<int>& nums,vector<int>& dp){
        if(i>=n-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(nums[i]==0){
            return 10000;
        }
        int ans=10000;
        for(int j=1;j<=nums[i];j++){
            ans=min(ans,1+solve(i+j,n,nums,dp));
        }
        return dp[i]=ans;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};