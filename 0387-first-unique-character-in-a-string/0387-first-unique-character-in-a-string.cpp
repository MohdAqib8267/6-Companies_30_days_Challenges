class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
         unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int ans=-1;
   for(int i=0;i<n;i++){
       if(mp[s[i]]==1){
           return i;
           break;
       }
   }
        return -1;
    }
};