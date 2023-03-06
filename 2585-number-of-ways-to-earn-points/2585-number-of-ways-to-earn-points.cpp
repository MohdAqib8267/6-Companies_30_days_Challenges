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
};