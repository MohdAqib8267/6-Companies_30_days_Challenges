class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        if(n==1){
            return false;
        }
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem==0 and i>=1){
                return true;
                break;
            }
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>=2){
                     return true;
                } 
            }else{
                 mp[rem]=i;
            }
           
        }
        return false;
    }
};