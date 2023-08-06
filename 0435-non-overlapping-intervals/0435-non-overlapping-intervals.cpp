class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[1]<b[1]){
            return true;
        }
        return false;
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);//for minimise[jo bdi range wale hinge unko htayenge]
        int i=0;
        int cnt=0;
        for(int j=1;j<n;j++){
            if(intervals[i][1]>intervals[j][0]){
                cnt++;
            }
            else{
                i=j;
            }
        }
        return cnt;
    }
};