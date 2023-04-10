class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        bool valid=true;
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')'){
                if(!st.empty() and st.top()=='('){
                    st.pop();
                }
                else{
                    valid=false;
                    break;
                }
            }
            else if(s[i]=='}'){
                if(!st.empty() and st.top()=='{'){
                    st.pop();
                }
                else{
                    valid=false;
                    break;
                }
            }
            else if(s[i]==']'){
                if(!st.empty() and st.top()=='['){
                    st.pop();
                }
                else{
                    valid=false;
                    break;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return valid;
    }
};