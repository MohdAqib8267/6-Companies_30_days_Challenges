class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int i=0,j=0;
        int res=INT_MIN;
        int mx=INT_MIN;
        while(j<s.size()){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            int len=j-i+1;
            if((len-mx)<=k){
                res=max(res,len);
            }else{
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return res;
    }
};