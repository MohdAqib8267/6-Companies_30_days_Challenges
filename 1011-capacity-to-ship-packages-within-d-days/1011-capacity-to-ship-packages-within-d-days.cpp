class Solution {
public:
    bool isPossible(vector<int>&weights,int mid,int days){
        int sum=0;
        int count=1;
        for(int i=0;i<weights.size();i++){
            sum=sum+weights[i];
            if(sum>mid){
                count++;
                sum=weights[i];
                if(sum>mid || count>days){
                    return false;
                }
            }
            // if(count>days){
            //     false;
            // }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int low=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int high=sum;
        int ans=sum;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(weights,mid,days)){
                ans=mid;
                high=mid-1;
                // if(sum>mid){
                //     return false;
                // }
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};