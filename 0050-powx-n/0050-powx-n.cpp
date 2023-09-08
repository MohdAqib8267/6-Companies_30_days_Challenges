class Solution {
public:
    double myPow(double x, int n) {
      if(n==0) return 1;
        if(n==1){
            return x;
        }
        if(n<0){
            n=abs(n);
            x=1/x;
        }
        double a=myPow(x,n/2);
        if(n%2==0){
            return a*a;
        }else{
            return a*a*x;
        }
    }
};