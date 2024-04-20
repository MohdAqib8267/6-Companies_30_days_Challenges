class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>>q;
        for(auto it:mp){
           q.push({it.second,it.first});
        }
        while(!q.empty() && k--){
            auto p=q.top();
            q.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};