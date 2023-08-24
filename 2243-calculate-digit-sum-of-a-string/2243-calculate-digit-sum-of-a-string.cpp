class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            int sum=0;
            string str="";
            int cnt=0;
            for(int i=0;i<s.size();i++){
                if(cnt!=k){
                    sum=sum+(s[i]-'0');
                cnt++;
                }
                else{
                    cout<<sum<<endl;
                    str+=to_string(sum);
                    sum=0;
                    cnt=0;
                    i--;
                } 
            }
          
                str+=to_string(sum);
            
            s=str;
        }
        return s;
    }
};