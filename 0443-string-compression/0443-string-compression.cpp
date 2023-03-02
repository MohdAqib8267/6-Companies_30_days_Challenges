class Solution {
public:
    int compress(vector<char>& chars) {
        string s="";
        
        int cnt=1;
        for(int i=0;i<chars.size();i++){
            
            if(s==""){
                s=s+chars[i];
            }
            else{
                if(chars[i]==s[s.size()-1]){
                    cnt++;
                }
                else{
                    if(cnt>1){
                       s=s+to_string(cnt); 
                    }
                    
                    s=s+chars[i];
                    
                    cnt=1;
                }
            }
        }
        if(cnt>1){
            s=s+to_string(cnt);
        }
        cout<<s;
        
        int j;
        for( j=0;j<s.size();j++){
            
               chars[j]=s[j];
        }
        return s.size();
    }
};