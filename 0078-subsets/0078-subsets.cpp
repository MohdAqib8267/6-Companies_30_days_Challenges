class Solution {
public:
    void solve(int i,int n,vector<int>& nums,vector<int>& temp,vector<vector<int>>& ans){
        if(i>=n){
            ans.push_back(temp);
            return;
        }
         temp.push_back(nums[i]);
        solve(i+1,n,nums,temp,ans);
        temp.pop_back();
        solve(i+1,n,nums,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
         solve(0,n,nums,temp,ans);
        return ans;
    }
};