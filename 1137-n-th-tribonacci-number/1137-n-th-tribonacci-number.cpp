class Solution {
public:
    int tribonacci(int n) {
        //T0+3=t0+t1+t2=0+1+1=2
        //n==1 t4=t1+t2+t3
        //n==2 t5=t2+t3+t4
        if(n==0){
            return n;
        }
        if(n==1 || n==2){
            return 1;
        }
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }
};