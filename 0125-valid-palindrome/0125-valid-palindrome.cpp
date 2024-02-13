class Solution {
public:
    bool Palindrome(string s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]>='A' and s[i]<='Z'){
                str+=(s[i]+32);
            }else if(s[i]>='a' and s[i]<='z'){
                str+=s[i];
            }else if(s[i]>='0' and s[i]<='9'){
                str+=s[i];
            }else{
                continue;
            }
        }
        cout<<str;
        return Palindrome(str,0,str.size()-1);
    }
};