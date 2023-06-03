class Solution {
public:
    bool isPalind(string str){
        int i=0;int j=str.size()-1;
        while(i<j){
            if(str[i]!=str[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str="";
        for(int i=0;i<s.size();i++){
           if(s[i]>='A' and s[i]<='Z'){
                str+=(s[i]+32);
            }
             if(s[i]>='a' and s[i]<='z'){
                str+=s[i];
            }
             if(s[i]>='0' and s[i]<='9'){
                str+=(s[i]);
            }
        }
        cout<<str;
        return isPalind(str);
    }
};