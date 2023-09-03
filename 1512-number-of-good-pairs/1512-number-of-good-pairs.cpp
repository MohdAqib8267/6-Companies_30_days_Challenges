class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int cnt=0;
       for(auto it:mp){
           cnt=cnt+(it.second*(it.second-1))/2;
       }
        return cnt;
    }
};