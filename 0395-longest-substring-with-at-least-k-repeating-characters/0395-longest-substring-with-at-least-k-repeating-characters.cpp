class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.size()==0 || k>s.size()) return 0;
        
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int i=0;
        while(i<s.size() and mp[s[i]]>=k){
            i++;
        }
        if(i==s.size()){
            return s.size();
        }
        int left=longestSubstring(s.substr(0,i),k);
        int right=longestSubstring(s.substr(i+1),k);
        return max(left,right);
    }  
};