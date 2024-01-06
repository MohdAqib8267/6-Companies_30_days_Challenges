class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<vector<int>>ans(nums.size());
        int j=0;
        for(int i=0;i<nums.size();i++){
            int ind=mp[nums[i]];
            ans[ind].push_back(nums[i]);
            mp[nums[i]]++;
        }
        vector<vector<int>>res;
        for(int i=0;i<ans.size();i++){
            if(ans[i].size()!=0){
                res.push_back(ans[i]);
            }
        }
        return res;
    }
};