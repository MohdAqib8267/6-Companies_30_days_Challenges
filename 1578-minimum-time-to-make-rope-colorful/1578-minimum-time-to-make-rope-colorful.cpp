class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.size();
//       "a a a  b b b a b b b b"
//       [3,5,10,7,5,3,5,5,4,8,1]
          
        int i=0;
        int ans=0;
        for(int j=1;j<n;j++){
            int mn=0;
            if(colors[i]==colors[j]){
                mn=min(neededTime[i],neededTime[j]);
                if(neededTime[i]<neededTime[j]){
                    i=j;
                }
            }
            else{
                i=j;
            }
            ans=ans+mn;
        }
        return ans;
    }
};