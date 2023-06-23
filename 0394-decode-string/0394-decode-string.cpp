class Solution {
public:
    string decodeString(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]==']'){
                string a = "";
                while(st.top()!='['){
                     a+=st.top();
                     st.pop();
                }
                reverse(a.begin(),a.end());
                st.pop();
                string r = "";
                while(!st.empty() and (st.top()>='0' and st.top()<='9')){
                    r+=st.top();
                    st.pop();
                }
                 reverse(r.begin(),r.end());
                int val = stoi(r);
                string c = "";
                while(val--){
                    c+=a;
                }
                for(int i=0;i<c.size();i++){
                     st.push(c[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }
        string b="";
        while(!st.empty()){
             b+=st.top();
             st.pop();
        }
        reverse(b.begin(),b.end());
        return b;
    }
};