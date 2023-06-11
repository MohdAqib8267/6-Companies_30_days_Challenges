class Solution {
public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        if(a.second>b.second){
            return true;
        }
        return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>temp(mp.begin(),mp.end());
         for(int i=0;i<temp.size();i++){
            cout<<temp[i].first<<"->"<<temp[i].second<<endl;
        }
        
        //sort in reverse order
        sort(temp.begin(),temp.end(),cmp);
        vector<int>ans;
        for(int i=0;i<temp.size();i++){
            cout<<temp[i].first<<"->"<<temp[i].second<<endl;
        }
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].first);
        }
        return ans;
    }
};