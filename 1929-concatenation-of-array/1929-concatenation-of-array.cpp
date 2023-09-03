class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>ans(nums.begin(),nums.end());
        int n=ans.size();
        for(int i=n;i<2*n;i++){
            ans.push_back(nums[i-n]);
        }
        return ans;
    }
};