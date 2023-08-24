class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elSum=0,dgSum=0;
        for(int i=0;i<nums.size();i++){
            elSum+=nums[i];
            while(nums[i]>0){
                dgSum+=(nums[i]%10);
                nums[i]=nums[i]/10;
            }
        }
        return abs(elSum-dgSum);
    }
};