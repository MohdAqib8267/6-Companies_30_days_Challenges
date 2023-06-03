class Solution {
public:
    void solve(int idx,int n,vector<int>& nums,vector<vector<int>>& ans){
        if(idx>=n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            solve(idx+1,n,nums,ans);
            swap(nums[idx],nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
         solve(0,n,nums,ans);
        return ans;
    }
};