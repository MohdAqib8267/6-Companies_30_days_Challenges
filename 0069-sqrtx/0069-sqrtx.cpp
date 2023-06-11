class Solution {
public:
    int mySqrt(int x) {
        int lo=0;
        int hi=x;
        if(x==0) return 0;
        int ans=0;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            long long sq = mid*mid;
            if(sq == (long long)x){
                return mid;
            }
            if(sq>(long long)x){
                hi=mid-1;
            }
            else{
                ans=mid;
                lo=mid+1;
            }
        }
        return ans;
    }
};