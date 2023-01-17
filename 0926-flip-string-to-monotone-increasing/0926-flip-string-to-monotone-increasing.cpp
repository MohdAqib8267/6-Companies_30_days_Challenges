class Solution {
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