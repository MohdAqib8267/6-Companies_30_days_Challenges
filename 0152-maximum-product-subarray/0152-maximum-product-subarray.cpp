class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int p=1;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            p=p*nums[i];
            maxi=max(p,maxi);
            if(p==0){
                p=1;
            }
        }
        cout<<maxi;
        p=1;
        for(int i=nums.size()-1;i>=0;i--){
            p=p*nums[i];
            maxi=max(p,maxi);
            if(p==0){
                p=1;
            }
        }
        return maxi;
    }
};