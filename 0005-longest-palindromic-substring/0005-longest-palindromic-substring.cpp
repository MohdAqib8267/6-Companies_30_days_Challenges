class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        int size=0;
        int st=-1;
        for(int i=0;i<n;i++){
            int lo=i-1, hi=i+1;
            while(lo>=0 && s[lo]==s[i]){
                lo--;
            }
            while(hi<n && s[i]==s[hi]){
                hi++;
            }
            while(lo>=0 && hi<n && s[lo]==s[hi]){
                lo--;
                hi++;
            }
            if(hi-lo-1 > size){
                st=lo+1;
                size = hi-lo-1;
            }
        }
        return s.substr(st,size);
    }
};