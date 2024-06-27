class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int>&temp,set<vector<int>>&s){
        if(i>=nums.size()){
            s.insert(temp);
         
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,s);
           temp.pop_back();
        solve(i+1,nums,temp,s);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>temp;
        solve(0,nums,temp,s);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};