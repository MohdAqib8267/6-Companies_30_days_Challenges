class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            int rem=sum%k;
             if(rem==0 and i>=1){ //bcs ho skta hai 0th index wala hi pura devide ho jaye but hume km se km do element chahye hai
            return true;

            }
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1){
                    return true;
                }
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};