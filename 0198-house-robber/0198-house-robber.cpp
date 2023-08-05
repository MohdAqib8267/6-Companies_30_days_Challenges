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
    int solveTab(vector<int>& nums){
         int n=nums.size();
        vector<int>dp(n+1,0);
        if(n==1){
            return nums[0];
        }
        dp[1]=nums[0];
        if(n>=2){
            dp[2]=max(nums[0],nums[1]);
            for(int i=3;i<=n;i++){
                int inc=nums[i-1]+dp[i-2];
                int exc=dp[i-1];
                dp[i]=max(inc,exc);
            }
        }
        return dp[n];
        
    }
    int space(vector<int>& nums){
         int n=nums.size();
        if(n==1){
            return nums[0];
        }
          int firstHouse=nums[0];
            int SecondHouse=max(nums[0],nums[1]);
        for(int i=3;i<=n;i++){
            int twoback=nums[i-1]+firstHouse;
            int oneback=SecondHouse;
            firstHouse=SecondHouse;
            SecondHouse=max(oneback,twoback);
        }
        return SecondHouse;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        // return solve(0,n,nums,dp);
        
        // return solveTab(nums);
        return space(nums);
    }
};