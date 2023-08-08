class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
       int i=0;
        int j=0;
        int sumofNotGrumpy=0;
        int windowSum=0;
        int maxWindowSum=0;
        //basically hum window (mintues ki) ka sum nikalte jayenge and 
        //maximise krenge and sum nikalenge pure din me jhan per grumpy nhi hai ab jo grumpy minutes wali window hogi usme jo not grumpy wala hai jo wo do baar count ho gya hoga isliye use minues krenge yhi dhyaan rkhey
        while(j<grumpy.size()){
            if(grumpy[j]==0){
                sumofNotGrumpy += customers[j]; // sum of not grumpies inside and outside the window
            }
            else{
                windowSum += customers[j]; // window ke ander grumpy walo ka sum
            }
            if(j-i+1 == minutes){
                maxWindowSum=max(maxWindowSum,windowSum);
                if(grumpy[i]==1){ windowSum -= customers[i]; }
                i++;
            }
            j++;
        }
        return sumofNotGrumpy+maxWindowSum;// sab not grumpies and window ke ander jo grumpy hai unka sum
    }
};