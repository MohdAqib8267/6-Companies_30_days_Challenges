class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        vector<string>ans;
        while(i<n){
            string s;
           int j=i+1;
            s+=to_string(nums[i]);
            int temp=i;
            while(j<n and nums[temp]+1 == nums[j]){
                temp++; j++;
            }
            if(i!=temp){
                s+="->";
                s+=to_string(nums[temp]); 
            }
             i=temp;
            i++;
          
            ans.push_back(s);
            s.clear();
        }
        return ans;
    }
};