class Solution {
public:
    void solve(int i,int n,vector<int>& nums,vector<int>& temp, set<vector<int>>&s){
        if(i>=n){
            if(temp.size()>1){
               s.insert(temp); 
            }
            
            return;
        }
        if(temp.size()==0 or temp.back()<=nums[i]){
            temp.push_back(nums[i]);
            solve(i+1,n,nums,temp,s);
            temp.pop_back();
            
        }
        solve(i+1,n,nums,temp,s);
        
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        vector<int>temp;
        solve(0,nums.size(),nums,temp,s);
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};