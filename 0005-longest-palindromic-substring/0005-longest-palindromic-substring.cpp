class Solution {
public:
    string longestPalindrome(string s) {
       int st=0;
        int lo,hi;
        int n=s.size();
        if(n<2){
            return s.substr(0,n);
        }
        int size=1;
        for(int i=0;i<n;i++){
            lo=i-1;
            hi=i+1;
            while(lo>=0 and s[i]==s[lo]){
                lo--;
            }
            while(hi<n and s[i]==s[hi]){
                hi++;
            }
            while(lo>=0 and hi<n and s[lo]==s[hi]){
                lo--;
                hi++;
            }
           int length=hi-lo-1;
            if(length>size){
                size=length;
                st=lo+1;
            }
        }
        return s.substr(st,size);
    }
};