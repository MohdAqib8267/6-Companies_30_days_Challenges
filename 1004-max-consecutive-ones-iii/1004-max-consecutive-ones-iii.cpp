class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int n=nums.size();
        int ans=INT_MIN;
        while(j<n){
            if(nums[j]==1){
                j++;
            }
            else{
                if(k>0){
                    k--;
                    j++;
                }
                else{
                    if(nums[i]==0){
                        k++;
                    }
                    i++;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};