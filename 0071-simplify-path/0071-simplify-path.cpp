class Solution {
public:
    string simplifyPath(string path) {
        int n=path.size();
        string res="";
        stack<string>st;
        for(int i=0;i<n;i++){
            if(path[i]=='/'){
                continue;
            }
            string temp="";
            while(i<path.size() and path[i]!='/'){
                temp=temp+path[i];
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
            res="/"+st.top()+res;
            st.pop();
        }
        return res;
    }
};