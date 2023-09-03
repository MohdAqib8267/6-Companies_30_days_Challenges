class Solution {
public:
    string reverseWords(string s) {
        int i=0;
        int n=s.size();
        //remove intialy empty space
        while(i<n and s[i]==' '){
            i++;
        }
        int j=n-1;
        //remove last empty space
        while(j>=0 and s[j]==' '){
            j--;
        }
        string temp;
        string ans;
        while(i<=j){
            if(s[i]==' '){
                while(s[i]==' '){
                    i++;
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