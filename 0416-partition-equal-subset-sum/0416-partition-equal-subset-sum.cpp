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
        //  vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        // return solve(0,target,0,nums,dp);
        
        //Tabulation
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    // Base case: A sum of 0 can always be achieved by not taking any elements
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // Fill the dp table iteratively
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            // Option 1: Don't take the current element
            bool notTake = dp[i - 1][j];

            // Option 2: Take the current element if it doesn't exceed the current target
            bool take = false;
            if (j >= nums[i - 1]) {
                take = dp[i - 1][j - nums[i - 1]];
            }

            // Update dp table
            dp[i][j] = take || notTake;
        }
    }

    // The result will be in dp[n][target], indicating whether we can achieve the target sum
    return dp[n][target];
    }
};