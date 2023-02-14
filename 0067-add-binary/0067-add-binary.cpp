class Solution {
public:
    string addBinary(string a, string b) {
       
      string ans="";
        int carry=0;
        int n=a.size();
        int m=b.size();
        int i=n-1;
        int j=m-1;
        while(i>=0 or j>=0 or carry!=0){
          int sum=0;
           
            if(i>=0){
                sum=sum+(a[i]-'0');
            }
            if(j>=0){
                sum=sum+(b[j]-'0');
            }
             sum=sum+carry;
            int ld=sum%2+'0';
            carry=sum/2;
            ans.push_back(ld);
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};