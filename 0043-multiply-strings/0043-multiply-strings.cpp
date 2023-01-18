class Solution {
public:
    string multiply(string num1, string num2) {
        int n=num1.size();
        int m=num2.size();
        if(num1=="0" or num2=="0"){
            return "0";
        }
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int N=n+m;
        string answer(N,'0');
        for(int i=0;i<m;i++){
            int digit1=num2[i]-'0';
            for(int j=0;j<n;j++){
                int digit2=num1[j]-'0';
                int pos=i+j;
                int carry=answer[pos]-'0';
                int multiplication=digit1*digit2 + carry;
                int lastdigit=multiplication % 10;
                carry= multiplication/10;
                answer[pos]=lastdigit+'0';
                answer[pos+1]=answer[pos+1]+carry;
            }
        }
        if(answer.back()=='0'){
            answer.pop_back();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};