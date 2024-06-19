class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int k, int day, int m) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long) m*k > n){
            return -1;
        }
        int lo=1;
        int hi=bloomDay[0];
        for(int i=0;i<n;i++){
            hi=max(hi,bloomDay[i]);
        }
        int ans=hi;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
           if(canMakeBouquets(bloomDay,k,mid,m)){
              
               ans=min(ans,mid);
               
               hi=mid-1;
           }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};