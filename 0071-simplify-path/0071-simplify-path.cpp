class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        stack<string>st;
        string s;
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                continue;
            }
            string temp;
            while(i<n and path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        if(st.empty()){
            return "/";
        }
        while(!st.empty()){
            s="/"+st.top()+s;
            st.pop();
        }
        return s;
    }
};