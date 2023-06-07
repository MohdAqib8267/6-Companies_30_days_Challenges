class Solution {
public:
    //kiranpalsingh1806


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
            
            int n1=nums1.size(), n2=nums2.size();
            int ans=0;
            vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
            for(int i=1;i<=n1;i++){
                for(int j=1;j<=n2;j++){
                    if(nums1[i-1]==nums2[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=0;
                    }
                    ans=max(ans,dp[i][j]);
                }
            }
            return ans;
    }
    
};