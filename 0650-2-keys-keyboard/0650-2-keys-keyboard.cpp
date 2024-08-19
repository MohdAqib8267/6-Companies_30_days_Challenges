class Solution {
public:
    int prime(int num){
        for(int i=num-1;i>1;i--){
            if(num%i==0){
                return i;
            }
        }
        return -1;
    }
    int solve(int n){
         if(n==1){
            return 0;
        }
        if(n==2) return 2;
        if(n==3) return 3;
        if(n==4 || n==5) return n;
        int divisor = prime(n);
        if(divisor == -1) return n;
        
        int cnt=n/divisor + solve(divisor);
        
        return cnt;
    }
    int minSteps(int n) {
       return solve(n);
        
    }
};