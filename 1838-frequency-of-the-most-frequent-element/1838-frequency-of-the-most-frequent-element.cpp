class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int i=0;
         long sum=0;
         int ans=0;
         sort(nums.begin(),nums.end());
       for (int j=0;j<nums.size();j++)
         {
           sum+=nums[j];
            //let's assume, we modify the all previous element till jth element and we would make all previous elements like ith element and check that number of operations less then k or not
            while((long)(j-i+1)*nums[j] - sum > k)
           {
               sum-=nums[i];
               i++;
           }
            ans=max(ans,j-i+1);
            
        }
        return ans;
    }
};