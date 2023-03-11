class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans;
        vector<int>temp(nums.begin(),nums.end());
        sort(temp.begin(),temp.end());
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(temp[i])!=mp.end()){
                continue;
            }
            mp[temp[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(mp[nums[i]]);
        }
        return ans;
    }
};