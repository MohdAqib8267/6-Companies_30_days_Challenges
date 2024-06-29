class Solution {
public:
   string longestPalindrome(string s) {
        int n=s.size();
        int ans=1;
        int st=0;
         if(n==1){
            return s;
        }
        for(int i=0;i<n;i++){
            int lo=i-1;
            int hi=i+1;
            while(lo>=0 and s[i]==s[lo]){
                lo--;
            }
            while(hi<n and s[i]==s[hi]){
                hi++;
            }
            while(lo>=0 and hi<n and s[hi]==s[lo]){
                lo--;
                hi++;
            }
            int size=hi-lo-1;
            if(ans<size){
                ans=size;
                st=lo+1;
            }
        }
        return s.substr(st,ans);
    }
};