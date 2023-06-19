class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')' or s[i]=='('){
                st.push({s[i],i});
                if(st.size()==1 and s[i]==')'){
                    s.erase(i,1);
                    st.pop();
                    i--;
                }
                else if(st.size()!=1){
                    if(s[i]==')'){
                        st.pop();
                        st.pop();
                    }
                }
            }
        }
        while(!st.empty()){
            s.erase(st.top().second,1);
            st.pop();
        }
        return s;
    }
};