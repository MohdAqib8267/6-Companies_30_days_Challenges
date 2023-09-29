class Solution {

      int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(i > j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        for(int ind = i; ind <= j; ind++)
        {
            int cost = nums[ind] * nums[i - 1] * nums[j + 1] + 
                        f(i, ind - 1, nums, dp) + f(ind + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }

        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return f(1, n - 2, nums, dp);
    }
};