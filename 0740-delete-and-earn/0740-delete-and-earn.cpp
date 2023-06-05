class Solution {
public:
    int solve(int i,vector<int>& nums,int n, vector<int>&dp){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=nums[i];
        int idx=i+1;
        //add into same element in sum 
        while(idx<n and nums[idx]==nums[i]){
            sum+=nums[idx];
            idx++;
        }
        //delete nums[i]+1 elements, we have been sort the element that's why dont need to delete nums[i]-1 elements
        while(idx<n and nums[idx]-nums[i]==1){
            idx++;
        }
        //include
        int include = sum+solve(idx,nums,n,dp);
        int exclude = solve(i+1,nums,n,dp);
        return dp[i] = max(include,exclude);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,-1);
        return solve(0,nums,n,dp);
    }
};