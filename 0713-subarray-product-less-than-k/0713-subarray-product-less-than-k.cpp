class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,prod=1;
        int cnt=0;
        if(k==0){
            return 0;
        }
        for(int j=0;j<n;j++){
            prod=prod*nums[j];
            while(i<=j && prod>=k){
                prod=prod/nums[i];
                i++;
            }
            cnt=cnt+(j-i+1);
        }
        return cnt;
    }
};