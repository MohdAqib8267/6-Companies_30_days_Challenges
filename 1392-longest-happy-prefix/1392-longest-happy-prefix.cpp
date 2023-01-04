class Solution {
public:
    string longestPrefix(string s) {
        //Brute Force
        // int n=s.size();
        //   if(n==1)
        // return "";
        // vector<string>pre,suff;
        // string x(1,s[0]);
        // string y(1,s[n-1]);
        // //for prefix
        // pre.push_back(x);
        // for(int i=1;i<s.size();i++)
        // {
        //     string temp=x+s[i];
        //     pre.push_back(temp);
        //     x=temp;
        // }
        // //for suffix
        // suff.push_back(y);
        // for(int i=n-2;i>0;i--){ //last element chod ker wrna same aa jayega
        //     string temp=s[i]+y;
        //     suff.push_back(temp);
        //     y=temp;
        // }
        // string ans="";
        // for(int i=0;i<n-1;i++){
        //     if(pre[i]==suff[i]){
        //         if(pre[i].size()>ans.size()){
        //             ans=pre[i];
        //         }
        //     }
        // }
        // return ans;
        
        //Optimsise using KMP Algorith
        
        int n=s.size();
        int i=1;
        int j=0;
        vector<int>temp(n,0);
        while(i<n){
            if(s[i]==s[j]){
                j++;
                temp[i]=j;
                i++;
            }
            else{
                if(j!=0){
                    j=temp[j-1];
                }
                else{
                     i++;
                }
               
            }
         
        }
       return s.substr(0,temp[n-1]);
    }
};