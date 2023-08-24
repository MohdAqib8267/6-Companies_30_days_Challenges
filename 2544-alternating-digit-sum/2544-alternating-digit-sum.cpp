class Solution {
public:
    int alternateDigitSum(int n) {
        string num=to_string(n);
        int sum=0;
        for(int i=0;i<num.size();i++){
            if(i%2==0){
                sum=sum+(num[i]-'0');
            }
            else{
                sum=sum-(num[i]-'0');
            }
        }
        return sum;
    }
};