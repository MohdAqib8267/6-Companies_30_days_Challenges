class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' or s[i]==')'){
                st.push({s[i],i});
                if(s[i]==')' and st.size()==1){
                    s.erase(i,1);
                    st.pop();
                    i--;
                }
                else if(st.size()!=1){
                    if(st.top().first==')'){
                        st.pop();
                        st.pop();
                    }
                }
            }
        }
        while(!st.empty()){
            int idx=st.top().second;
            s.erase(idx,1);
            st.pop();
        }
        return s;
    }
};