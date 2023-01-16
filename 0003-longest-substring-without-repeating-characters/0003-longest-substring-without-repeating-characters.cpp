class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<char,int>mp;
        while(j<n and i<n){
            if(mp[s[j]]<1){
                mp[s[j]]++;
                j++;
            }
           else{
               mp[s[i]]--;
               i++;
           }
            ans=max(ans,j-i);
        }
        return ans;
    }
};