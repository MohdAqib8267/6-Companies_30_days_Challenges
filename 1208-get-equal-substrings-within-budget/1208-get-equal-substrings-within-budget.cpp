class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0;
        int j=0;
        int sum=0;
        int ans=0;
        while(j<n){
            sum+=abs(t[j]-s[j]);
            if(sum>maxCost){
                sum-=abs(t[i]-s[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};