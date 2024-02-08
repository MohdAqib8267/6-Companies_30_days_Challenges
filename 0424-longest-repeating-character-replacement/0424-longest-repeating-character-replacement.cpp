class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        int res=INT_MIN;
        int mx=INT_MIN;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            int len=j-i+1;
            if((len-mx)<=k){
                res=max(len,mx);
               
            }else{
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return res;
    }
};