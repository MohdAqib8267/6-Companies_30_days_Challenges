class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        int i=0,j=1;
        if(n==0){
            return ans;
        }
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[i]);
        while(j<n){
            if(ans[i][1]>=intervals[j][0]){
                ans[i][1]=max(ans[i][1],intervals[j][1]);
            }else{
                ans.push_back(intervals[j]);
                i++;
            }
            
            j++;
        }
        return ans;
    }
};