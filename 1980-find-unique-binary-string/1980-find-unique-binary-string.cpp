class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();//2
        string ans;
        for(int i=0;i<n;i++){
            if(nums[i][i]=='0'){
                ans.push_back('1');
            }else{
                 ans.push_back('0');
            }
        }
        return ans;
    }
};