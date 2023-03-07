class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();
        long long st=0;
        long long en=1e14;
        for(int i=0;i<time.size();i++){
            en=en+time[i];
        }
        long long ans=1e9;
        while(st<=en){
            long long mid=st+(en-st)/2;
            long long cnt=0;
            for(int i=0;i<n;i++){
                cnt=cnt+mid/time[i];
            }
            
            if(cnt>=totalTrips){
                ans=min(ans,mid);
                en=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        return st;
    }
};