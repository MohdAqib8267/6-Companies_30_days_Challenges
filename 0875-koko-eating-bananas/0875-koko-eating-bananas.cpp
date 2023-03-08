class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int st=1;
        int en=1e9;
       
        int ans;
        while(st<=en){
            int mid=st+(en-st)/2;
            long long cntHour=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0){
                    cntHour=cntHour+(long long)(piles[i]/mid);
                }
                else{
                    cntHour=cntHour+(long long)(piles[i]/mid)+1;
                } 
            }
            
            if(cntHour<=h){
                ans=mid;
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return ans;
    }
};