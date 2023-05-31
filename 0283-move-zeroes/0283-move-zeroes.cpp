class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int st=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[st++]=nums[i];
            }
            else{
                cnt++;
            }
        }
        while(cnt--){
            nums[st++]=0;
        }
        return;
    }
};