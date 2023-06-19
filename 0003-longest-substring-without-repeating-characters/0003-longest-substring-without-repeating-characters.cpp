class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
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