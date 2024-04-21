class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string ans=countAndSay(n-1);
        //"1" & n==2
        int cnt=1;
        string str="";
        for(int i=0;i<ans.size();i++){
            while(ans[i] == ans[i+1]){
                cnt++;
                i++;
            }
            str=str+to_string(cnt)+ans[i];
            cnt=1;
        }
        return str;
        
    }
};