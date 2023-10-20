class Solution {
public:
    string countAndSay(int n) {
           if(n==1){
            return "1";
        }
        string ans=countAndSay(n-1);
       string res="";
        
        for(int i=0;i<ans.size();i++){
            int cnt=1;
           while(ans[i]==ans[i+1] and i<ans.size()){
               cnt++;
               i++;
           }
            res=res+to_string(cnt)+ans[i];
        }
        return res;

    }
};