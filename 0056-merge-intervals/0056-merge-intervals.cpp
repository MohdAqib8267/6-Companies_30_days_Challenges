class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int j=1;
        ans.push_back(intervals[0]);
        while(j<n){
            if(ans[i][1]>=intervals[j][0]){
                ans[i][1]=max(ans[i][1],intervals[j][1]);
                j++;
            }else{
                ans.push_back(intervals[j]);
                i++;
                j++;
            }
        }
        return ans;
    }
};