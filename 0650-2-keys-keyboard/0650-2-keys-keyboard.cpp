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
        int higestDivisor = prime(n);
        if(higestDivisor == -1) return n;
        
        int cnt=n/higestDivisor + solve(higestDivisor);
        
        return cnt;
    }
    int recursion(int step, int val,int copy,int n){
        if(step>n || val>n){
            return INT_MAX;
        }
        if(val==n){
            return step;
        }
        // return min step to reach the target value
        // there are 2 choices: paste copied value with current value => 1 step
        // copy current value and paste it with itself => 2 step
        int pasteOneStep = recursion(step+1,val+copy, copy, n);
        int copypasteTwoStep = recursion(step+2,2*val,val,n);
        return min(pasteOneStep,copypasteTwoStep);
        
    }
    int minSteps(int n) {
       // return solve(n); // Prime number approach

        //DP approach
        if(n==1){
            return 0;
        }
        //assume that we have copy the number(1 step done) and my value is A
        // return recursion(1,'A','A',n); //step 1, current Val 'A', copy item 'A',
        // here we need n, A's so we can show A-->1
        return recursion(1,1,1,n);
        
    }
};