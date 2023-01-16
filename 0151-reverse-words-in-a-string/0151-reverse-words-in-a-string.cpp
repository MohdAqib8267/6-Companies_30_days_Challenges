class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        int i=0;
        string ans="";
        while(i<n){
            while(i<n and s[i]==' '){ // it may contain leading multiple spaces
                i++;
            }
             if(i>=n){
                break;
            }
            int j=i+1;
            while(j<n and s[j]!=' '){
                j++;
            }
            string str=s.substr(i,j-i);
            if(ans.size()==0){
                ans=ans+str;
            }
            else{
                ans=str+' '+ans;
            }
            i=j+1;
        }
        return ans;
    }
};