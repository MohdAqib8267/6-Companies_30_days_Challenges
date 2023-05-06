class Solution {
public:
     int mod=1e9+7;
    int power(int x,int y){
        if(y==0){
            return 1;
        }
        if (y==1){
            return 2;
        }
        long long ans=1;
        if(y%2==0){
           ans=power(x,y/2);
           ans*=ans%mod;
        }
        else{
            ans=power(x,y-1);
            ans*=x;
        }
        return ans%mod;
    }
    int numSubseq(vector<int>& nums, int target) {
          int s=0,e=nums.size()-1;
        sort(nums.begin(),nums.end());
        int ans=0;
        while(s<=e){
            if(nums[s]+nums[e]<=target){
                ans+=power(2,e-s);
                ans=ans%mod;
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};