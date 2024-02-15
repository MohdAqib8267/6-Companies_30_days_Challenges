class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int prod=1;
        int mx=INT_MIN;
        //form left
        for(int i=0;i<n;i++){
            prod=prod*nums[i];
            mx=max(mx,prod);
            if(nums[i]==0){
                prod=1;
            }
        }
        prod=1;
        for(int i=n-1;i>=0;i--){
            prod=prod*nums[i];
            mx=max(mx,prod);
            if(nums[i]==0){
                prod=1;
            }
        }
        return mx;
    }
};