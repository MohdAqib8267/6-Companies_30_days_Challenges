class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        int k=1;
        int ans=0;
        while(j<n){
            if(nums[j]==0){
                k--;
                if(k<0){
                    while(i<j and nums[i]!=0){
                        cnt--;
                        i++;
                    }
                    i++;
                    k++;
                }
            }else{
                cnt++;
            }
            ans=max(ans,cnt);
            j++;
            
        }
        if(ans==n){
            return ans-1;
        }
        return ans;
    }
};