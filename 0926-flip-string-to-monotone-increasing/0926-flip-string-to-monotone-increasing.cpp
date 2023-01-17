class Solution {
    //DP
//     The base case is dp[0] = 0, since an empty string is always monotone increasing. Consider dp[i] for i > 0,

// If s[i - 1] = '1', then we have dp[i] = dp[i - 1], since we can always append a character '1' to the end of a monotone increasing string and it's still monotone increasing.

// If s[i - 1] = '0', let's consider whether we flip it or not.

// If we don't flip it, we have to flip all the '1's in s before it.
// If we flip it, then we can treat it as the above case where s[i - 1] = '1' with one more flip.
// In summary,

// Let number num be the number of character 1s in s' prefix of length i:

// dp[i] = dp[i - 1] if s[i - 1] = '1'
// dp[i] = min(num, dp[i - 1] + 1) otherwise.
// The final answer should be dp[s.length()]

// Since dp[i] only depends on dp[i - 1], we can use a simple int variable instead of an array to reduce the space complexity.
public:
    int minFlipsMonoIncr(string s) {
        // int n=s.size();
        // //without DP
        // int count_zero=0;
        // int count_flip=0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='0'){
        //         count_zero++;
        //     }
        //     else{
        //         count_flip++;
        //     }
        //     count_zero=min(count_zero,count_flip);
        // }
        // return count_zero;
        
        //with DP
        int n=s.size();
        vector<int>dp(n+1,0);
        int count_one=0;
        for(int i=1;i<n+1;i++){
           if(s[i-1]=='0'){
              //then we have 2 option(0,0,1,1,0) let we have on the 4th index then 
               //2 options-->1. if we dont flip it then before s[i] all elements shoul
               //be zero means (2 one ko flip krna hoga )
              //2. if we flip then 1+dp[i-1] ek to flip krne ka and count usser peechey k
               dp[i]=min(count_one,1+dp[i-1]);
               
           }
            else{
                count_one++;
                dp[i]=dp[i-1];
            }
        }
        return dp[n];
    }
};