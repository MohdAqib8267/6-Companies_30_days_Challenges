class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=0;
        int hi=0;
        for(int i=0;i<n;i++){
            lo=max(lo,weights[i]);
            hi+=weights[i];
        }
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int curr=0;
            int cnt=1;
            for(int i=0;i<n;i++){
                curr+=weights[i];
                if(curr>mid){
                    curr=weights[i];
                    cnt++;
                    if(curr>mid){
                        
                        lo=mid+1;
                        continue;
                    }
                }
            }
            if(cnt<=days){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
         }
        return ans;
    }
};