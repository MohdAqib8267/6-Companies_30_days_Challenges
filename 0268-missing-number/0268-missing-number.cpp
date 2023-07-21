class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(cnt==nums[i]){
               cnt++; 
            }
            else{
                break;
            }
            
        }
        return cnt;
    }
};