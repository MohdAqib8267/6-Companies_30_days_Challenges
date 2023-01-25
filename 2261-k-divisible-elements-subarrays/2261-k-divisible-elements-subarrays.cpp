class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>>s;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            int count=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%p == 0){
                    count++;
                }
                if(count>k){
                    break;
                }
                temp.push_back(nums[j]);
                s.insert(temp);
            }
        }
        return s.size();
    }
};