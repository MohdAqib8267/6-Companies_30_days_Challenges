class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       
        //TLE
//         for(int i=0;i<n;i++){
//             int sum=0;
//             int ind=(i-1+n)%n; //prev index
//             for(int j=i;j<n+i;j++){
//                 sum=sum+nums[j%n];
              
//                 mx=max(mx,sum);
//             }
            
//         }
//         return mx;
        
        //2.nd method
      // int n=nums.size();
      //   int ans=INT_MIN;
      //   int sum=0;
      //   vector<int>dp(n);
      //   for(int i=0;i<n;i++){
      //       sum+=nums[i];
      //       if(sum<0){
      //           sum=0;
      //       }
      //       ans=max(ans,sum);
      //   }
      //   //now check maximum subarray sum till ith element
      //   sum=0;
      //   for(int i=0;i<n;i++){
      //       sum=sum+nums[i];
      //       dp[i]=max(i>0?dp[i-1] :nums[i], sum);
      //   }
      //   int cur=0;
      //   for(int i=n-1;i>=1;i--){
      //       cur+=nums[i];
      //       ans=max(ans,dp[i-1]+cur);
      //   }
      //   return ans;
        
        // This will store minimum sum
    int mini = 0;
    // This will store max sum
    // I have initalize it with INT_MIN so that in case of an array
    // with all negative values it dont take maxi as ZERO
    int maxi = INT_MIN;
    
    // This will store sum of our nums array
    int sum = 0;
    
    // temporary variable for finding minimum sum
    int t1=0;
     // temporary variable for finding max sum
    int t2=0;
    
    for(int i = 0 ; i<nums.size();i++){
        // finding sum of nums array
        sum+=nums[i];
        
        // finding minimum sum of the subarray
        t1 = min(nums[i]+t1,nums[i]);
        mini = min(t1,mini);
        
        // finding maximum sum of the subarray
        t2 = max(nums[i]+t2,nums[i]);
        maxi = max(t2,maxi);
    }
    // if array consist of only negative elements
    if(sum==mini){
        return maxi;
    }
    return max(maxi,sum-mini);
    }
};