class Solution {
public:
    //Here i and j denoted first and last of stick
    // and s and e denoted start and end of cuts array
    int solve(int s,int e,vector<int>& cuts,int i,int j,vector<vector<int>>&dp){
        if(s>e) return 0;
        if(dp[s][e]!=-1){
            return dp[s][e];
        }
        int ans=INT_MAX;
        for(int idx=s;idx<=e;idx++){
            
            int left = solve(s,idx-1,cuts,i,cuts[idx],dp);
            int right = solve(idx+1,e,cuts,cuts[idx],j,dp);
            ans=min(ans,(left+right+j-i));
        }
        return dp[s][e]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(0,cuts.size()-1, cuts, 0,n,dp);
    }
};