class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int NGS=0;
        int wSum=0;
        int maxSum=0;
        int i=0;
        int j=0;
        while(j<n){
            if(grumpy[j]==0){
                NGS+=customers[j];
            }
            else{
                wSum+=customers[j];
            }
                if(j-i+1==minutes){
                    maxSum=max(maxSum,wSum);
                    if(grumpy[i]==1){
                        wSum=wSum-customers[i];
                    }
                    
                    i++;
                
               
            }
            j++;
        }
        return NGS+maxSum;
    }
};