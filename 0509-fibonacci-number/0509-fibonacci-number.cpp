class Solution {
public:
    int solve(int n){
        if(n==0 || n==1){
            return n;
        }
        return solve(n-1)+solve(n-2);
    }
    int fib(int n) {
        // return solve(n);
        
        if(n==0 || n==1){
            return n;
        }
        int prev1=0;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int newNum=prev1+prev2;
            prev1=prev2;
            prev2=newNum;
        }
        return prev2;
    }
};