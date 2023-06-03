class Solution {
public:
    void solve(int idx,int n,vector<int>& nums,set<vector<int>>&s){
        if(idx>=n){
            s.insert(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[idx],nums[i]);
            solve(idx+1,n,nums,s);
            swap(nums[idx],nums[i]);
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        solve(0,nums.size(),nums,s);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};