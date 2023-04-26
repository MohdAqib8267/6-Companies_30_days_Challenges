class Solution {
public:
    int addDigits(int num) {
      int sum=0;
        while(num>9){
            int temp=num%10;
            sum=sum+temp;
            num=num/10;
            if(num<10){
                num=num+sum;
                sum=0;
            }
        }
        return num;
    }
};