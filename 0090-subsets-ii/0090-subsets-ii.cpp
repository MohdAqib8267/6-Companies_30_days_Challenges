class Solution {
public:
    void solve(int i,int n,vector<int>&temp,set<vector<int>>&s,vector<int>&nums){
        if(i>=n){
            sort(temp.begin(),temp.end());
            s.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,n,temp,s,nums);
        temp.pop_back();
        solve(i+1,n,temp,s,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        solve(0,nums.size(),temp,s,nums);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};