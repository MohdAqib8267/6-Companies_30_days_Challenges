class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1;
        set<int>s2;
        for(auto i:nums1){
            s1.insert(i);
        }
        for(auto i:nums2){
            s2.insert(i);
        }
        unordered_map<int,bool>mp;
        for(auto x:s2){
            mp[x]=true;
        }
        vector<vector<int>>ans;
        vector<int>v1;
        vector<int>v2;
        for(auto it:s1){
            if(mp.find(it)==mp.end()){
                v1.push_back(it);
            }
            else{
                mp[it]=false;
            }
        }
        for(auto it:mp){
            if(it.second==true){
                v2.push_back(it.first);
            }
        }
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};