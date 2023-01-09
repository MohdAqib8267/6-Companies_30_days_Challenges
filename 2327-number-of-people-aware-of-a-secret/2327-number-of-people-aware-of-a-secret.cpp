class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //DP approach
        //initialise a sigle dp with 0
        //dp[1]=1; //at day 1, definetiely 1 people discover 1 secret
        //2 nested loop
        //when (jth day+delay<=ith day) then we can share the secret
        //   and one people share 1 secret so dp[i]=dp[i]+dp[j];
        // if(jth day+forget<= ith day) then jth day loose your secre
        // so dp[i]=dp[i]-dp[j]; //loose dp[j]
        
              int mod=1e9+7;
        long long dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;//base case
        long long ans=0;
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
               if(i-j>=delay and i-j<forget){
                   dp[i]=(dp[i]+dp[j])%mod;
               }
        }
        }
        for(int i=0;i<n+1;i++){
            if(n-forget<i){
                ans=(ans+dp[i])%mod; //unhe count krey jo jinda rhenge
            }
        }
        //   for(int j=max(1,n-forget+1);j<=n;j++){
        //     ans=(ans+dp[j])%mod;
        // }
        return ans;
    }
};