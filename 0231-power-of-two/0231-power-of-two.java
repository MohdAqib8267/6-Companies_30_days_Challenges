class Solution {
    public boolean isPowerOfTwo(int n) {
        //1st method
        // if(n<=0){
        //     return false;
        // }
        // while(n%2==0){
        //     n=n/2;
        // }
        // if(n==1){
        //     return true;
        // }
        // return false;
        
        //2nd
        if(n<=0){
            return false;
        }
        return (n & (n-1))==0?true:false;
    }
}