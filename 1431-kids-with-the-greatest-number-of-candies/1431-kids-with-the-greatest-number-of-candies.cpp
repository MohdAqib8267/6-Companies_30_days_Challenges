class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>ans;
        int mx=INT_MIN;
        for(int i=0;i<candies.size();i++){
            mx=max(mx,candies[i]);
        }
        for(int i=0;i<candies.size();i++){
            int curr=candies[i]+extraCandies;
            if(curr>=mx){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};