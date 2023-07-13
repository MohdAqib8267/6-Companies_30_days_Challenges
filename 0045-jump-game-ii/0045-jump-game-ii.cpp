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
int solveTab(vector<int>& arr){
    int n=arr.size();
      vector<int> dp(n, INT_MAX);

    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j <= min(n - 1, i + arr[i]); j++)
        {
            if (dp[j] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }
    return dp[0];

}
    
    //my recursion approach(memoize kre)
 int solve(int i,vector<int>& arr,int n, vector<int>&dp){
    if(i>=n-1){
        return 0;
    }
    if(arr[i]==0){
        return 1e9;;
    }
    if(dp[i]!=-1) return dp[i];
    int ans=1e9;
    for(int j=i+1;j<=min(arr[i]+i,n-1);j++){
        ans=min(ans,1+solve(j,arr,n,dp));
    }
    return dp[i]=ans;
}
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        // return solve(0,n,nums,dp);
        // return solveTab(nums);
        return solve(0,nums,n,dp);
    }
};