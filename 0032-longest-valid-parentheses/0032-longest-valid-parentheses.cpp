class Solution {
public:
    int longestValidParentheses(string s) {
         int n = s.length(),maxi=0;
    stack<int>st;
    st.push(-1);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') st.push(i);
        else 
        {
            st.pop();
            if(st.empty()) st.push(i);
            else
            {
                int len=i-st.top();
                maxi=max(maxi,len);
            }
        }
    }
    return maxi;
    }
};