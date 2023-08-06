class Solution {
public:
     int solve(int i,vector<int>& nums,int n,vector<int>& dp){
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
         for(int j=i+1;j<=min(nums[i]+i,n-1);j++){
        ans=min(ans,1+solve(j,nums,n,dp));
    }
        return dp[i]=ans;
    }
    bool canJump(vector<int>& nums) {
         int n=nums.size();
        // vector<int>dp(n+1,-1);
        // // return solve(0,n,nums,dp);
        // //DP solution
        // return solve(0,nums,n,dp)==10000?false:true;
        
        int maxJ=0;
        for(int i=0;i<n;i++){
            if(maxJ<i){
                return false;
            }
            maxJ=max(maxJ,i+nums[i]);
        }
        return true;
    }
};