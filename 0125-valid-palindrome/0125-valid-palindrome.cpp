class Solution {
public:
    bool solve(string s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
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
            }
            if(s[i]>='0' and s[i]<='9'){
                str+=s[i];
            }
            if(s[i]>='a' and s[i]<='z'){
                str+=s[i];
            }
        }
        cout<<str;
        if(solve(str)){
            return true;
        }
        return false;
    }
};