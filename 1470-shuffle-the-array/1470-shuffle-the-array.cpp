class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i=0,j=1;
        vector<int>ans;
        for(int i=0,j=n;i<n && j<2*n;i++,j++){
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
        }
        return ans;
    }
};