class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>st;
        int j=0;
        for(int i=0;i<n;i++){
            st.push(pushed[i]);
            while(!st.empty() and popped[j]==st.top()){
                st.pop();
                j++;
            }
        }
        if(st.empty() and j==popped.size()){
            return true;
        }
        return false;
    }
};