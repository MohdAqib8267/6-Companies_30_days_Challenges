class Solution {
public:
   int digit_sq_sum(int n){
        int sum=0;
        while(n>0){
            int last_digit=n%10;
            sum=sum+last_digit*last_digit;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        //method 1
        unordered_map<int,int>mp;
        while(n!=1){
            if(mp[n]==0){
                mp[n]++;
            }
            else{
                //cycle form
                return false;
                break;
            }
            n=digit_sq_sum(n);
        }
        return true;

        //method 2
        // if(n==1) return true;
        // if(n==4) return false;
        // return isHappy(digit_sq_sum(n));
    }
};