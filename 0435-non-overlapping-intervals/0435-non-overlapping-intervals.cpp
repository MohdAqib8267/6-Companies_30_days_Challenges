class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i=0;
        int j=1;
        int ans=0;
        sort(intervals.begin(),intervals.end(),cmp);
        if(n==1){
            return ans;
        }
        while(j<n){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
            }
            else{
                ans++;
            }
            j++;
        }
        return ans;
    }
};