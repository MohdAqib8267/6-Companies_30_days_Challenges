class Solution {
public:
//     static bool cmp(vector<int>& a,vector<int>& b){
        
//     }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=1;
        while(j<intervals.size()){
            if(intervals[i][1]>=intervals[j][0]){
                if(intervals[i][1]<intervals[j][1]){
                    intervals[i][1]=intervals[j][1];
                }
                j++;
            }
            else{
                ans.push_back(intervals[i]);
                i=j;
                j++;
            }
        }
        ans.push_back(intervals[i]);
        return ans;
    }
};