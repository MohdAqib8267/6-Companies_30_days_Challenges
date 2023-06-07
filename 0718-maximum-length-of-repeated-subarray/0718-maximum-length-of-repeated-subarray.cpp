class Solution {
public:
    //kiranpalsingh1806


    int lcs(vector<int>& s1 , vector<int>& s2 , int i , int j , int& maxVal,vector<vector<int>>& dp)
{
    if(i<0 || j<0){
        return 0;
    }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    int val = 0;
    if(s1[i] == s2[j]){
        val = 1 + lcs(s1,s2,i-1,j-1,maxVal,dp);
        maxVal = max(maxVal , val);
    }

    lcs(s1,s2,i-1,j,maxVal,dp);
    lcs(s1,s2,i,j-1,maxVal,dp);

    return dp[i][j]=val;
}
        int findLength(vector<int>& nums1, vector<int>& nums2) {
        
//         if (A.size() < B.size()) swap(A, B);
//         int M = A.size(), N = B.size();
//         vector<int> dp(N + 1, 0);
//         int ans = 0;
        
//         for(int i = 0; i < M; i++) {
//             for(int j = N - 1; j >= 0; j--) {
                
//                 if (A[i] == B[j]) {
//                     dp[j + 1] = 1 + dp[j];
//                 } else {
//                     dp[j + 1] = 0;
//                 }
                              
//                 ans = max(ans, dp[j + 1]);
//             }
            
//         }
        
//         return ans;
            
            //Memoization
            int maxVal = 0;
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    lcs(nums1,nums2,m-1,n-1,maxVal,dp);

    return maxVal;
            
            //Tabulation
            // int n1=nums1.size(), n2=nums2.size();
            // int ans=0;
            // vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
            // for(int i=1;i<=n1;i++){
            //     for(int j=1;j<=n2;j++){
            //         if(nums1[i-1]==nums2[j-1]){
            //             dp[i][j]=1+dp[i-1][j-1];
            //         }
            //         else{
            //             dp[i][j]=0;
            //         }
            //         ans=max(ans,dp[i][j]);
            //     }
            // }
            // return ans;
    }
    
};