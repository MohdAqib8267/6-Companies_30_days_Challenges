class Solution {
public:
//     MLE
//     int solve(int i,int sup1,int sup2,vector<int>& rods,int n,vector<vector<vector<int>>>&dp){
//         if(i>=n){
//             if(sup1==sup2){
//                 return sup1;
//             }
//             return 0;
//         }
//         if(dp[i][sup1][sup2]!=-1) return dp[i][sup1][sup2];
//         int takeSup1=solve(i+1,sup1+rods[i],sup2,rods,n,dp);
//         int takeSup2=solve(i+1,sup1,sup2+rods[i],rods,n,dp);
//         int notTake=solve(i+1,sup1,sup2,rods,n,dp);
//         return dp[i][sup1][sup2] = max({takeSup1,takeSup2,notTake});
//     }
//     int tallestBillboard(vector<int>& rods) {
//         int n=rods.size();
        
//         int support1=0,support2=0;
//         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(5001,vector<int>(5001,-1)));
//         return solve(0,support1,support2,rods,n,dp);
//     }
    // optimisation O(N2)
   int solver(vector<int>& rods, int i, int diff, int dp[][10001]){
        if(i == rods.size()){
            if(diff == 0) return 0;
            return -6000;
        }
        if(dp[i][diff+5000] != -1) return dp[i][diff+5000];

        int option1 = solver(rods,i+1,diff,dp);
        int option2 = rods[i] + solver(rods,i+1,diff+rods[i],dp);
        int option3 = rods[i] + solver(rods,i+1,diff-rods[i],dp);

        return dp[i][diff+5000] = max(option1,max(option2,option3));
    }
    int tallestBillboard(vector<int>& rods) {
        int dp[21][10001];
        memset(dp,-1,sizeof(dp));
        return solver(rods,0,0,dp)/2;
    }
};