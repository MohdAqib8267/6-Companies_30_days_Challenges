class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int a=abs(nums[i])-1;
            nums[a]=-1*nums[a];
            if(nums[a]>0){
                return a+1;
            }
        }
        return -1;
    }
};