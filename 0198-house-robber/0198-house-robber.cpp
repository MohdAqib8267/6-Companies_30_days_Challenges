class Solution {
public:
    int solve(int i,vector<int>& nums,int n,vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int take=nums[i]+solve(i+2,nums,n,dp);
        int not_take=solve(i+1,nums,n,dp);
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        // return solve(0,nums,n,dp);
        
        //Tabulation
//         vector<int>dp(n+1,INT_MAX);
        
//         dp[1]=nums[0];
//         if(n>1) dp[2]=max(nums[0],nums[1]);
//         for(int i=3;i<n+1;i++){
//             dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
//         }
//         return dp[n];
        
        //Space optimisation
         int one=nums[0];
        if(n==1){
            return one;
        }
        int two;
        if(n>1) two=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int curr=max(nums[i]+one,two);
            one=two;
            two=curr;
        }
        return two;
    }
};