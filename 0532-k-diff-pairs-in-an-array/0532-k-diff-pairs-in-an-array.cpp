class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int cnt=0;
        for(auto x:nums){
            mp[x]++;
        }
        for(auto it:mp){
            int temp=it.first+k;
            if(k!=0){
                if(mp.find(temp)!=mp.end()){
                    cnt++;
                }
            }else{
                if(it.second>1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};