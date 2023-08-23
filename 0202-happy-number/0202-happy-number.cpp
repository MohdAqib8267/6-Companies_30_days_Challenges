class Solution {
public:
    int find(int n){
        int sum=0;
        while(n>0){
            int ld=(n%10);
            sum=sum+(ld*ld);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if(n==1){
            return true;
        }
        if(n==4){
            return false;
        }
        bool ans=true;
        while(n!=1){
            int newNum=find(n);
            cout<<newNum<<endl;
            
            if(newNum==4){
                ans=false;
                break;
            }
            n=newNum;
        }
        return ans;
    }
};