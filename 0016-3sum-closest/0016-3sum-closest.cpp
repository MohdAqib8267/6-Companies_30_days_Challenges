class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans;
        for(int i=0;i<nums.size();i++){
            int l=i+1;
            int h=nums.size()-1;
            while(l<h){
                 int sum=nums[i]+nums[l]+nums[h];
            if(sum==target){
                return sum;
            }
            else if(abs(sum-target)<diff){
                diff=abs(sum-target);
                ans=sum;
            }
            if(sum<target){
                l++;
            }
            else{
                h--;
            }
            }
           
        }
        return ans;
    }
};