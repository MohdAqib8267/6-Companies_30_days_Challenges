class Solution {
public:
    //memoization
    int solve(int n,int m,vector<int>& nums1,vector<int>& nums2,vector<vector<int>>& dp){
        if(n==0 or m==0 ){
            return 0;
        }
        if(dp[n-1][m-1]!=-1){
            return dp[n-1][m-1];
        }
        else if(nums1[n-1]==nums2[m-1]){
            dp[n-1][m-1]= 1+solve(n-1,m-1,nums1,nums2,dp);
        }
        else{
            dp[n-1][m-1]= max(solve(n-1,m,nums1,nums2,dp),solve(n,m-1,nums1,nums2,dp));
        }
        return dp[n-1][m-1];
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //like longest subsequenece DP Wale swaal
        //memoization
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n,m,nums1,nums2,dp);
        
        
        //tabulation
//          	int n1 = nums1.size(), n2 = nums2.size(), i, j;
// 	vector<vector<int>> res(n1+1, vector<int>(n2+1, -1));
// 	for(i=0; i<n1+1; ++i){
// 		for(j=0; j<n2+1; ++j){
// 			if(i==0 || j==0){
// 				res[i][j]=0;
// 				continue;
// 			}
// 			if(nums1[i-1]==nums2[j-1]){
// 				res[i][j] = max(1+res[i-1][j-1], max(res[i-1][j], res[i][j]));
// 			}else{
// 				res[i][j]=max(res[i-1][j], res[i][j-1]);
// 			}
// 		}
// 	}
// 	return res[n1][n2];
    
    }
};