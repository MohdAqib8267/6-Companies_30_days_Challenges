class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i] != "+" and s[i]!="-" and s[i]!="*" and s[i]!="/"){
                st.push(stoi(s[i]));
            }
            else{
                int op2=st.top();
                st.pop();
                int op1=st.top();
                st.pop();
                if(s[i]=="+"){
                    st.push(op1+op2);
                }
                else if(s[i]=="-"){
                    st.push(op1-op2);
                }
                else if(s[i]=="*"){
                    st.push(op1*op2);
                }
                else{
                    st.push(op1/op2);
                }
            }
        }
        return st.top();
    }
};