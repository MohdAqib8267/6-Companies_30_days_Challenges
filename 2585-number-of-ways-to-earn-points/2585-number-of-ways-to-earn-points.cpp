class Solution {
public:
    int mod=1e9+7;
    int solve(int ind,int currsum,int target,vector<vector<int>>& types,int n,vector<vector<int>>&dp){
        if(currsum==target){
            return 1;
        }
        if(currsum>target){
            return 0;
        }
        if(ind==n){
            if(currsum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][currsum]!=-1){
            return dp[ind][currsum];
        }
        int take=0;
        int not_take=0;
        
        for(int i=1;i<=types[ind][0];i++){
            take=(take+solve(ind+1,currsum+i*types[ind][1],target,types,n,dp)%mod)%mod;
        }
        not_take = (not_take+solve(ind+1,currsum,target,types,n,dp)%mod)%mod;
        
        return dp[ind][currsum]=(take+not_take)%mod;
        
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        //DP
        int n=types.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,0,target,types,n,dp);
        
    }
    
    //2nd method like knapsack
    //   int dfs(int ind, int target, vector<int>& ques, vector<int>& marks, int n, vector<vector<int>> & dp) {
    //     int mod = 1e9 + 7;
    //     if (target == 0) return 1;
    //     if (target < 0 || ind < 0) return 0;
    //     if (dp[ind][target] != -1) return dp[ind][target];
    //     int ans = 0;
    //     for (int i=0; i<=ques[ind]; i++) {
    //         ans = (ans + dfs(ind-1, target-marks[ind]*i, ques, marks, n, dp))% mod;
    //     }
    //     return dp[ind][target] = ans;
    // }
    // int waysToReachTarget(int target, vector<vector<int>>& types) {
    //     int n = types.size();
    //     vector<int> ques, marks;
    //     vector<vector<int>> dp(n, vector<int>(target+1, -1));
    //     for (auto &type:types) {
    //         ques.emplace_back(type[0]);
    //         marks.emplace_back(type[1]);
    //     }
    //     return dfs(n-1, target, ques, marks, n, dp);
    // }
};