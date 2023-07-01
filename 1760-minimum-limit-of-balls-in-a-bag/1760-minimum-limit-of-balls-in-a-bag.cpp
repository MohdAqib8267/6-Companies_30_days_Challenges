class Solution {
public:
      bool cando(int maxx,int maxops,vector<int>& nums){
        int n = nums.size();
        long long ops=0;
        for(int i=0;i<n;i++){
            ops+=(nums[i]/maxx);
            if(nums[i]%maxx==0) ops--;
        }
        return ops<=maxops;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1;
        int right=1000000000;
        int mid;
        int ans=1000000000;
        while(left<=right){
            mid = (left+right)/2;
            if(cando(mid,maxOperations,nums)){
                ans = min(ans,mid);
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};