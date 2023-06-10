class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        //1. find how many elements exists in left and right side of index
        //bcz total element is n (toh kaam aasan ho gya)
        long r=n-index-1;
        long l=index;
        
        //so basically, we have to maximize index element, that's why we can use binary search
        long lo=1, hi=maxSum;
        long res=0;// our final ans at index
        while(lo<=hi){
            long mid=lo+(hi-lo)/2;
            //now check to assign mid at index, and left and right side element goes to decrease
            //[1,2,3,2] // 3 at index 2, and left and right of index decrease
            long sum=mid;
            long ls=0; //sum on left side of index
            long rs=0; //sum on right side if index
            long m=mid-1; //basically, m define no of element can occur at left and right side
            
            //for right side
            if(r<=m){
                //its mean, space nhi bachenge
                rs=m*(m+1)/2 - (m-r)*(m-r+1)/2; // 1 to m tak ka sum- (1 to (m-r) tk ka sum)
            }
            else{
                //extra space bachenge to unme 1 bhar denge
                rs=m*(m+1)/2 + 1*(r-m);
            }
            //similarly for left side
            if(l<=m){
                ls=m*(m+1)/2 - (m-l)*(m-l+1)/2;
            }
            else{
                ls=m*(m+1)/2 + 1*(l-m);
            }
            sum=sum+ls+rs;
            if(sum<=maxSum){
                res=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            
        }
        return res;
    }
};