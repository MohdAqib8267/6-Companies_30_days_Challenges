class Solution {
public:
    int DigitSum(int n){
        int sum=0;
        while(n>0){
            sum=sum+(n%10);
            n=n/10;
        }
        return sum;
    }
    int countEven(int num) {
        int cnt=0;
        for(int i=2;i<=num;i++){
            int dgsum=DigitSum(i);
            if(dgsum%2==0){
                cnt++;
            }
        }
        return cnt;
    }
};