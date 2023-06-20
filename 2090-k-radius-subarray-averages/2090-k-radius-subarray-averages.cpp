class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(n<(2*k+1)){
            return ans;
        }
         long long int sum=0;
        for(int i=0;i<(2*k+1);i++){
            sum+=nums[i];
        }
       //sliding window technique
        int total_num=(2*k+1);
        int avg=sum/total_num;
        int i=k;
        ans[k]=avg;
        for( i=k+1;i<=n-k-1;i++){
            sum=sum-nums[i-k-1];
            sum=sum+nums[i+k];
            ans[i]=sum/total_num;
        }
        return ans;
    }
};