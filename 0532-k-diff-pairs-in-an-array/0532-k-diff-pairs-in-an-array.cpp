class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        set<int>s;
        for(int i=0;i<n;i++){
            // s.insert(nums[i]);
            mp[nums[i]]++;
        }
        int cnt=0;
        for(auto x:mp){
            int temp=x.first+k;
            if(k!=0){
                 if(mp.find(temp)!=mp.end()){
                cnt++;
                }  
            }else{
                if(x.second>1){
                    cnt++;
                }
            }
           
        }
        return cnt;
    }
};