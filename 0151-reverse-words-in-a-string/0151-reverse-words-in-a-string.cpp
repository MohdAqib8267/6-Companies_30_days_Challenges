class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.size();
        while(i<n and s[i]==' '){
            i++;
        }
        string temp;
        string ans;
        while(i<n){
            if(s[i]==' '){
                while(s[i]==' '){
                    i++;
                }
                if(i>=n){
                    break;
                }
                i--;
                if(ans.size()==0){
                    ans=ans+temp;
                }
                else{
                    ans=temp+' '+ans;
                }
                
                temp="";
                
            }
            else{
                temp.push_back(s[i]);
            }
            i++;
        }
        if(temp.size()==n){
            ans=temp;
        }else
        ans=temp+' '+ans;
      
        
        return ans;
    }
};