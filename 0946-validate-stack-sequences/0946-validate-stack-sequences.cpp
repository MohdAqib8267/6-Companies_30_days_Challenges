class Solution {
public:
     bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        if(pushed.size() != popped.size()) return false;
        int n = pushed.size();
        stack<int> st;
        int j = 0;
        for(int i = 0; i < n && j < n; i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && popped[j] == st.top()) {
                st.pop();
                j++;
            }
        }
        if(st.empty() && j == popped.size()) return true;
        return false;
    }
};