class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int st=0;
        if(n==1){
            return s;
        }
        int ans=1;
        for(int i=0;i<n;i++){
            int j=i-1;
            int k=i+1;
            while(j>=0 and s[i]==s[j]){
                j--;
            }
            while(k<n and s[i]==s[k]){
                k++;
            }
            while(j>=0 and k<n and s[j]==s[k]){
                j--;
                k++;
            }
            if(ans<(k-j-1)){
                ans=k-j-1;
                st=j+1;
            }
        }
        return s.substr(st,ans);
    }
};