class Solution {
public:
 int f(vector<int>&nums, int used,int turn,vector<vector<int>>&dp){
        int m = nums.size();
        if(used == (1<<m)-1) return 0;
        if(dp[used][turn]!=-1) return dp[used][turn];
        int ans = INT_MIN;
        for(int i=0;i<m;i++){
            if(used & (1<<i)) continue;
            for(int j=i+1;j<m;j++){
                if(used & (1<<j)) continue;
                int new_used = used | (1<<i) | (1<<j);
                int work = turn * gcd(nums[i],nums[j]);
                ans = max(ans,f(nums,new_used,turn+1,dp) + work);
            }
        }
        return dp[used][turn]=ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp((1<<n),vector<int>(n/2 + 1, -1));
        return f(nums,0,1,dp);
    }
};