class Solution {
public:
    void solve(int i,vector<int>&nums,int n,set<vector<int>>&st,vector<int>temp){
        if(i>=n){
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,n,st,temp);
        temp.pop_back();
        solve(i+1,nums,n,st,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>st;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp;
        solve(0,nums,n,st,temp);
        for(auto it:st){
            sort(it.begin(),it.end());
            ans.push_back(it);
        }
        return ans;
    }
};