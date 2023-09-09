class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        if(num1=="0" || num2=="0"){
            return "0";
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int N=n+m;
        string ans(N,'0');
        for(int i=0;i<m;i++){
            int digit2=num2[i]-'0';
            for(int j=0;j<n;j++){
                int digit1=num1[j]-'0';
                int pos=i+j;
                int carry=ans[pos]-'0';
                int mul=digit1*digit2+carry;
                int ld=mul%10;
                carry=mul/10;
                ans[pos]=ld+'0';
                ans[pos+1]+=carry;
            }
        }
        if(ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};